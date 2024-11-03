#include "get_next_line.h"

int	main(void)
{
	int	fd;
	char 	*str = "";

	fd = open("test_txt/variable_nls.txt", O_RDONLY);
	if (fd < 0)
	{
		write (1, "ERRO to open fd", 16);
		close(fd);
		return (0);
	}

	while (str != NULL)
	{
		str = get_next_line(fd);
		if (str != NULL)
		{
			printf ("%s", str);
			free(str);
		}
	}
	printf ("%s", str);

	return (0);
}
