/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:09:40 by flima             #+#    #+#             */
/*   Updated: 2024/11/01 14:34:00 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_strchr_gnl(const char *str, int c);
static char	*set_strings(char *line);
static char	*get_current_line(int fd, char *buffer, char *rest_line);

static char	*get_current_line(int fd, char *buffer, char *rest_line)
{
	ssize_t	nbyte;
	char	*temp;

	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(rest_line);
			return (NULL);
		}
		else if (nbyte == 0)
			break ;
		buffer[nbyte] = '\0';
		if (rest_line == NULL)
			rest_line = ft_strdup("");
		temp = rest_line;
		rest_line = ft_strjoin(temp, buffer);
		free(temp);
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (rest_line);
}

static char	*set_strings(char *line)
{
	unsigned int	i;
	char			*rest_line;

	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\0' || line[1] == '\0' || line[i + 1] == '\0')
		return (NULL);
	rest_line = ft_substr(line, (i + 1), (ft_strlen(line) - i));
	if (*rest_line == 0)
	{
		free(rest_line);
		rest_line = NULL;
	}
	line[i + 1] = '\0';
	return (rest_line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*rest_of_line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest_of_line);
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(rest_of_line);
		return (NULL);
	}
	line = get_current_line(fd, buffer, rest_of_line);
	free(buffer);
	buffer = NULL;
	if (line == NULL)
		return (NULL);
	rest_of_line = set_strings(line);
	return (line);
}

static char	*ft_strchr_gnl(const char *str, int c)
{
	size_t	i;
	char	chr;

	i = 0;
	chr = (char)c;
	while (str[i])
	{
		if (str[i] == chr)
			return ((char *)str + i);
		i++;
	}
	if (str[i] == chr)
		return ((char *)str + i);
	return (NULL);
}
