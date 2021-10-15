#include "fdf.h"

int coordinate_insert(int i, char **temp, t_win *win)
{
	int j;
	int k;
	int l;
	char **z_info;

	j = -1;
	while (temp[++j])
	{
		z_info = ft_split(temp[j], ',');
		win->map->values[i][j].z = ft_atoi(z_info[0]);
		win->map->values[i][j].color = 0xFFFFFF;
		k = 1;
		if (z_info[1])
			win->map->values[i][j].color = hex_to_int(z_info[1]);
		free(temp[j]);
	}
}

int map_info_insert(char *filename, t_win *win)
{
	int i;
	int fd;
	char *line;
	char **temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (_ERROR);
	i = 0;
	while (get_next_line(fd, &line))
	{
		win->map->values[i] = malloc(sizeof(t_value *) * win->map->width);
		if (!win->map->values[i])
			return (_ERROR);
		temp = ft_split(line, ' ');
		free(line);
		coordinate_insert(i, temp, win);
		i++;
		free(temp);
	}
	close(fd);
}

int map_reader(char *filename, t_win *win)
{
	if (map_checker(filename, win) < 0)
		return (map_error(MAP_INFO_ERROR, win));
	if (map_make(win) < 0)
		return (map_error(MAP_MAKE_ERROR, win));
	if (map_info_insert(filename, win) < 0)
	 	return (map_error(MAP_INSERT_ERROR, win));
	map_setting(win);
	return (TRUE);
}