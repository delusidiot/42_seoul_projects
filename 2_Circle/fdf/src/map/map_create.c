#include "fdf.h"

int	map_init(t_win *win)
{
	win->map = NULL;
	win->color = NULL;
	win->map = malloc(sizeof(t_map));
	if (!win->map)
		return (_ERROR);
	win->color = malloc(sizeof(t_color));
	if (!win->color)
	{
		if (win->map)
			free(win->map);
		return (_ERROR);
	}
	win->map->width = -1;
	win->map->height = 0;
	return (TRUE);
}

void	map_setting(t_win *win)
{
	win->map->shift_x = WIN_WIDTH / 4;
	win->map->shift_y = 50;
	win->map->magnify_z = 1.00;
	win->map->angle_x = cos(M_PI / 3);
	win->map->angle_y = sin(M_PI / 6);
	win->map->rotate_x = 0;
	win->map->rotate_y = 0;
	////
	win->map->coordinate_z = 0;
	win->map->coordinate_y = 0;
	win->map->x_value = 1.00;
	win->map->angle_y = cos(M_PI / 3);
	win->map->angle_z = win->map->angle_y * sin(M_PI / 6);
	// win->map->zoom = 40;
	win->map->zoom = win->map->zoom =ceil((win->map->width > win->map->height)) \
		? (WIN_WIDTH / win->map->width) + MAGIC_ZOOM \
		: (WIN_HEIGHT / win->map->height) + MAGIC_ZOOM;
	win->map->isometric = 1;
	win->color->red = 0x4F;
	win->color->green = 0x4F;
	win->color->blue = 0x4F;
}

void	map_make(t_win *win){
	int i;

	i = -1;
	win->map->values = malloc(sizeof(t_coor *) *(win->map->height));
	while (++i < win->map->height){
		win->map->values[i] = NULL;
	}
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
	free(win->map);
	win->map = NULL;
	write(2, message, ft_strlen(message));
	return (FALSE);
}