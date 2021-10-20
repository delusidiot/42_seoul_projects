#include "fdf.h"

int	init_camera(t_win *win)
{
	win->camera = (t_camera *)malloc(sizeof(t_camera) * 1);
	if (!win->camera)
		put_error("camera initialization error");
	win->camera->alpha = 0;
	win->camera->beta = 0;
	win->camera->gamma = 0;
	win->camera->x_offset = 0;
	win->camera->y_offset = 0;
	win->camera->projection = ISOMETRIC;
	win->camera->zoom = \
			int_min((WIN_WIDTH) / win->map->width / 2,
			WIN_HEIGHT / win->map->height / 2);
	if (win->camera->zoom <= 0)
		win->camera->zoom = 1;
	win->camera->z_magnify = 1;
	return (TRUE);
}

void	reset_camera(t_win *win)
{
	win->camera->alpha = 0;
	win->camera->beta = 0;
	win->camera->gamma = 0;
	win->camera->x_offset = 0;
	win->camera->y_offset = 0;
	win->camera->zoom = \
			int_min((WIN_WIDTH) / win->map->width / 2,
			WIN_HEIGHT / win->map->height / 2);
	win->camera->z_magnify = 1;
}