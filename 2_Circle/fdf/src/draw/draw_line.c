#include "fdf.h"

void	isometric(float *x, float *y, int z, t_win *win)
{
	*x = (*x - *y) * win->map->angle_x;
	*y = (*x + *y) * win->map->angle_y - z;
}

int	 color_selector(int z, int z1, int z_color, t_win *win)
{
	int color;

	color = 0xFFFFFF;
	if (!z && !z1)
		return (color);
	if (z_color != color)
		color = z_color;
	else
		color = win->map->default_color;
	return (color);
}

void	bresenham(float x, float y, float x1, float y1, t_win *win)
{
	t_step step;
	int max;
	int z;
	int z1;
	int color;

	// ------------color-------
	z = win->map->values[(int)y][(int)x].z * win->map->magnify_z;
	z1 = win->map->values[(int)y1][(int)x1].z * win->map->magnify_z;
	color = color_selector(z, z1, win->map->values[(int)y][(int)x].color, win);

	// -----------zoom---------
	x *= win->map->zoom;
	y *= win->map->zoom;
	x1 *= win->map->zoom;
	y1 *= win->map->zoom;
	// ===========3d==========
	if (win->map->angle_x != 0)
	{
		isometric(&x, &y, z, win);
		isometric(&x1, &y1, z1, win);
	}
	// -----------shift---------
	x += win->map->shift_x;
	x1 += win->map->shift_x;
	y += win->map->shift_y;
	y1 += win->map->shift_y;

	step.x_step = x1 - x; // x 변위
	step.y_step = y1 - y; // y 변위
	max = float_max(float_mod(step.x_step), float_mod(step.y_step));
	step.x_step /= max;
	step.y_step /= max;
	while ((int)(x - x1) || (int)(y - y1))
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, color);
		x += step.x_step;
		y += step.y_step;
	}
}

int draw_map(t_win *win)
{
	int x;
	int y;

	y = 0;
	while (y < win->map->height){
		x = 0;
		while (x < win->map->width){
			if (x < win->map->width - 1)
				bresenham(x, y, x + 1, y, win);
			if (y < win->map->height - 1)
				bresenham(x, y, x, y + 1, win);
			x++;
		}
		y++;
	}
	return (0);
}