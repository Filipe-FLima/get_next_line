/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flima <flima@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/28 18:09:40 by flima             #+#    #+#             */
/*   Updated: 2024/11/03 20:17:53 by flima            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*set_strings(char **line);
static char	*get_current_line(int fd, char *buffer, char *rest_of_line);
static char	*set_line(char *current_line, unsigned int len);

static char	*get_current_line(int fd, char *buffer, char *rest_of_line)
{
	ssize_t	nbyte;
	char	*temp;

	nbyte = 1;
	while (nbyte > 0)
	{
		nbyte = read(fd, buffer, BUFFER_SIZE);
		if (nbyte < 0)
		{
			free(rest_of_line);
			return (NULL);
		}
		else if (nbyte == 0)
			break ;
		buffer[nbyte] = '\0';
		if (rest_of_line == NULL)
			rest_of_line = ft_strdup("");
		temp = rest_of_line;
		rest_of_line = ft_strjoin(temp, buffer);
		free(temp);
		temp = NULL;
		if (ft_strchr_gnl(buffer, '\n'))
			break ;
	}
	return (rest_of_line);
}

static char	*set_strings(char **line)
{
	unsigned int	i;
	char			*rest_of_line;
	char			*temp;

	i = 0;
	while ((*line)[i] != '\n' && (*line)[i] != '\0')
		i++;
	if ((*line)[i] == '\0' || (*line)[1] == '\0' || (*line)[i + 1] == '\0')
		return (NULL);
	temp = *line;
	*line = set_line(temp, i + 1);
	if (*line == NULL)
	{
		free(temp);
		return (NULL);
	}
	rest_of_line = ft_substr(temp, (i + 1), (ft_strlen(temp) - i));
	free(temp);
	return (rest_of_line);
}

char	*get_next_line(int fd)
{
	char			*buffer;
	char			*line;
	static char		*rest_of_line[1024];

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(rest_of_line[fd]);
		rest_of_line[fd] = NULL;
		return (NULL);
	}
	buffer = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (buffer == NULL)
	{
		free(rest_of_line[fd]);
		rest_of_line[fd] = NULL;
		return (NULL);
	}
	line = get_current_line(fd, buffer, rest_of_line[fd]);
	free(buffer);
	if (line == NULL)
		return (NULL);
	rest_of_line[fd] = set_strings(&line);
	return (line);
}

static char	*set_line(char *current_line, unsigned int len)
{
	unsigned int	i;
	char			*new_line;

	if (current_line == NULL)
		return (NULL);
	new_line = (char *)malloc((len + 1) * sizeof(char));
	if (new_line == NULL)
		return (NULL);
	i = 0;
	while (current_line[i] != '\n')
	{
		new_line[i] = current_line[i];
		i++;
	}
	new_line[i] = '\n';
	new_line[len] = '\0';
	return (new_line);
}
