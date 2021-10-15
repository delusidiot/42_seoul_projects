#include "fdf.h"

int	map_init(t_win *win)
{
	win->map = NULL;
	win->map = malloc(sizeof(t_map));
	if (!win->map)
		return (_ERROR);
	win->map->width = -1;
	win->map->height = 0;
	return (TRUE);
}

void	map_setting(t_win *win)
{
	win->map->shift_x = WIN_WIDTH / 3;
	win->map->shift_y = 50;
	win->map->magnify_z = 1.00;
	win->map->angle_x = cos(M_PI / 3);
	win->map->angle_y = cos(M_PI / 3);
	win->map->angle_z = win->map->angle_y * sin(M_PI / 6);
	win->map->zoom = win->map->zoom =ceil((win->map->width > win->map->height)) \
		? (WIN_WIDTH / win->map->width) + MAGIC_ZOOM \
		: (WIN_HEIGHT / win->map->height) + MAGIC_ZOOM;
	win->map->isometric = 1;
	win->map->color = 0;
	win->map->default_color = 0xFF;
}

int	map_make(t_win *win){
	int i;

	i = -1;
	win->map->values = malloc(sizeof(t_value *) *(win->map->height));
	if (!win->map->values)
		return (_ERROR);
	while (++i < win->map->height){
		win->map->values[i] = NULL;
	}
	return (TRUE);
}

void	map_free(t_win *win)
{
	int i;
	
	i = -1;
	if (win->map->values != NULL){
		while (++i < win->map->height){
			free(win->map->values[i]);
		}
		free(win->map->values);
		win->map->values = NULL;
	}
	free(win->map);
	win->map = NULL;
}

int	map_error(char *message, t_win *win)
{
	//free(win->map);
	win->map = NULL;
	write(2, message, ft_strlen(message));
	return (FALSE);
}