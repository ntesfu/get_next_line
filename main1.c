#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "get_next_line.h"
#include <stdio.h>

//#include "get_next_line.c"
//#include "get_next_line_utils.c"

//# define BUFFER_SIZE 8

int main(void)
{
	int fd;
	
	size_t  len = 0;
	char    *line;

	fd = open("test.txt", O_RDONLY);
	int fd2 = open("tt", O_RDONLY);
	if (fd == -1 || fd2 == -1)
		printf("Error opening the file\n");
	line = get_next_line(fd);
	char *line2 = get_next_line(fd2);
	len = ft_strlen(line);
	int i = 0;
	while (i != 5)
	{   
		//printf("Retrieved line of length %zu:\n", ft_strlen(line));
		printf("%s", line);
		printf("%s", line2);
		line = get_next_line(fd);
		line2 = get_next_line(fd2);
		len = ft_strlen(line);
		i++;
	}
	close(fd);
	if (line)
		free(line);
}
