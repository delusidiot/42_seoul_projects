#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

void ft_print(char *str)
{
	int i = 0;
	while(str[i])
		i++;
	write(1, str, i);
}

int main(void)
{
	char *rst = NULL;
	char *file1 = "file2.txt";
	int iseof;
	int inf = 100;

	int fd = open(file1, O_RDONLY);
	while((iseof = get_next_line(fd, &rst)))
	{
		if (rst)
			ft_print(rst);
		if (iseof == 1)
			write(1, " +", 2);
		else if (iseof == -1)
			write(1, " -", 2);
		write(1, "\n", 1);
		if (inf < 0)
			break;
		inf--;
	}
	return (0);
}
