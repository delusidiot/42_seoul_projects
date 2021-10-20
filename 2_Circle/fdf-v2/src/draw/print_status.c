#include "fdf.h"

void	print_control(t_win *win)
{
	int y;

	y = 0;
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 20, 0xFFFFFF, "<Controls>");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "key W/A/S/D : move");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "key B/N : zoom");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "key J/K : z_magnify");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "key space : projection");
}

void	print_status(t_win *win)
{
	int		y;
	char	buf[10];

	y = 150;
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 60, 0xFFFFFF, "<Status>");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "x_offset: ");
	sprintf(buf, "%d", win->camera->x_offset);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 115, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%d", win->camera->y_offset);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "y_offset: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 115, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%d", win->camera->zoom);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "zoom: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 75, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->z_magnify);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "z_magnify: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 75, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->alpha);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "alpa: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 75, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->beta);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "beta: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 75, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->gamma);
	mlx_string_put(win->mlx_ptr, win->win_ptr, 15, y += 30, 0xFFFFFF, "gamma: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr, 75, y += 0, 0xFFFFFF, buf);
}