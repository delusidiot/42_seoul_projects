#include "fdf.h"

int static coordinate_check(char *temp){
	int i;
	char **z_info;

	z_info = ft_split(temp, ',');
	i = -1;
	if (!is_number(z_info[0]))
		return (put_error("is_number\n"));
	if (z_info[1] && !is_hex(z_info[1]))
		return (put_error("is_hex\n"));
	i = -1;
	while (z_info[++i])
		free(z_info[i]);
	free(z_info);
	free(temp);
	return (TRUE);
}

int map_checker(char *filename, t_win *win)
{
	int i;
	int j;
	int fd;
	char *line;
	char **temp;

	fd = open(filename, O_RDONLY);
	if (map_init(win) < 0 && fd < 0)
		return (put_error("file or init\n"));
	while (get_next_line(fd, &line))
	{
		i = -1;
		temp = ft_split(line, ' ');
		while (temp[++i])
			if (coordinate_check(temp[i]) < 0)
				return (put_error("coordinate_check\n"));
		free(temp);
		free(line);
		if (win->map->width != -1 && i != win->map->width)
			return (put_error("width\n"));
		win->map->width = i;
		win->map->height++;
	}
	close(fd);
	return (TRUE);
}