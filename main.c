#include "get_next_line.h"
# include <stdio.h>
# include <fcntl.h>

//echo -e "line\nline1\nline3\n" | ./a.out

//use a file.txt to read
// int	main(void)
// {
// 	int	fd;
// 	char 	*str = "";

// 	fd = open("test_txt/variable_nls.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write (1, "ERRO to open fd", 16);
// 		close(fd);
// 		return (0);
// 	}

// 	while (str != NULL)
// 	{
// 		str = get_next_line(fd);
// 		if (str != NULL)
// 		{
// 			printf ("%s", str);
// 			free(str);
// 		}
// 	}
// 	printf ("%s", str);

// 	return (0);
// }

//read from the terminal

int main(void)
{
    char *str;

    while (str!= NULL)
    {
        str = get_next_line(STDIN_FILENO);
		if (str != NULL)
		{
			printf ("%s", str);
			free(str);
		}
    }
	printf ("%s", str);
	
    return 0;
}

// int	main(void)
// {
// 	int	fd;
// 	int	fd1;
// 	int	fd2;
// 	char 	*str = "";
// 	char 	*str1 = "";
// 	char 	*str2 = "";

// 	fd = open("test_txt/variable_nls.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write (1, "ERRO to open fd", 16);
// 		close(fd);
// 		return (0);
// 	}
// 	fd1 = open("test_txt/lines_around_10.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write (1, "ERRO to open fd1", 17);
// 		close(fd);
// 		return (0);
// 	}
// 	fd2 = open("test_txt/read_error.txt", O_RDONLY);
// 	if (fd < 0)
// 	{
// 		write (1, "ERRO to open fd2", 17);
// 		close(fd);
// 		return (0);
// 	}

// 	while (str != NULL || str1 != NULL || str2 != NULL)
// 	{
// 		str = get_next_line(fd);
// 		if (str != NULL)
// 		{
// 			printf ("%s", str);
// 			free(str);
// 		}
// 		str1 = get_next_line(fd1);
// 		if (str1 != NULL)
// 		{
// 			printf ("%s", str1);
// 			free(str1);
// 		}
// 		str2 = get_next_line(fd2);
// 		if (str2 != NULL)
// 		{
// 			printf ("%s", str2);
// 			free(str2);
// 		}
// 	}
// 	printf ("\nEOFs");

// 	return (0);
// }
