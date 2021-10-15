#include "fdf.h"

int coorditate_check(char *temp){
	int i;
	char **z_info;

	z_info = ft_split(temp, ',');
	i = -1;
	if (!is_number(z_info[0]))
		return (_ERROR);
	if (z_info[1] && !is_hex(z_info[1]))
		return (_ERROR);
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
	if (fd < 0)
		return (_ERROR);
	if (map_init(win) < 0)
		return (_ERROR);
	while (get_next_line(fd, &line))
	{
		i = -1;
		temp = ft_split(line, ' ');
		while (temp[++i])
			if (coorditate_check(temp[i]) < 0)
				return (_ERROR);
		free(temp);
		free(line);
		if (win->map->width != -1 && i != win->map->width)
			return (_ERROR);
		win->map->width = i;
		win->map->height++;
	}
	close(fd);
	return (TRUE);
}

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
		return map_error(MAP_READ_ERROR, win);
	
	i = 0;
	while (get_next_line(fd, &line))
	{
		win->map->values[i] = malloc(sizeof(t_coor *) * win->map->width);
		if (!win->map->values[i])
			return map_error(MAP_COORDINATE_ERROR, win);
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
		return map_error(MAP_INFO_ERROR, win);
	// map_make(win);
	// if (map_info_insert(filename, win) < 0)
	// 	return map_error(MAP_INFO_ERROR, win);
	// map_setting(win);

	/**/
	int i;
	int j;
	printf("%d %d\n", win->map->height, win->map->width);
	for(i = 0; i<win->map->height; i++){
		for(j = 0; j<win->map->width; j++)
			printf("%d,%#X ", win->map->values[i][j].z, win->map->values[i][j].color);
		printf("\n");
	}
	/**/
	return (TRUE);
}