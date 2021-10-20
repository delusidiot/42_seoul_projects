#include "fdf.h"

static int coordinate_insert(int i, char **temp, t_win *win)
{
	int j;
	char **z_info;

	j = -1;
	while (temp[++j])
	{
		z_info = ft_split(temp[j], ',');
		win->map->values[i][j].z = ft_atoi(z_info[0]);
		if (win->map->z_max < win->map->values[i][j].z)
			win->map->z_max = win->map->values[i][j].z;
		if (win->map->z_min > win->map->values[i][j].z)
			win->map->z_min = win->map->values[i][j].z;
		win->map->values[i][j].color = 0;
		if (z_info[1])
			win->map->values[i][j].color = hex_to_int(z_info[1]);
		free(temp[j]);
	}
	return (TRUE);
}

static int map_info_insert(char *filename, t_win *win)
{
	int i;
	int fd;
	char *line;
	char **temp;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (FALSE);
	i = 0;
	while (get_next_line(fd, &line))
	{
		win->map->values[i] = malloc(sizeof(t_value *) * win->map->width);
		if (!win->map->values[i])
			return (FALSE);
		temp = ft_split(line, ' ');
		free(line);
		coordinate_insert(i, temp, win);
		i++;
		free(temp);
	}
	close(fd);
	return (TRUE);
}

int map_reader(char *filename, t_win *win)
{
	if (!map_checker(filename, win))
		return (map_error(MAP_INFO_ERROR, win));
	if (!map_make(win))
		return (map_error(MAP_MAKE_ERROR, win));
	if (!map_info_insert(filename, win))
	 	return (map_error(MAP_INSERT_ERROR, win));
	return (TRUE);
}