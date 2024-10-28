#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int fd = open("shrek.txt", O_RDONLY);
	char *s = get_next_line(fd);
	int i = 0;
	while (s)
	{
		printf("[%03i]> %s$\n",i, s);
		free(s);
		s = get_next_line(fd);
		i++;
	}
	free(s);
	return 0;
}
