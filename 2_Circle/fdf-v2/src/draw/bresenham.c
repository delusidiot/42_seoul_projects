#include "fdf.h"

static void	init_delta_and_step(t_coor *c1, t_coor *c2, t_coor *delta, t_coor *step)
{
	delta->x = int_abs(c2->x - c1->x);
	delta->y = int_abs(c2->y - c1->y);
	if (c1->x < c2->x)
		step->x = 1;
	else
		step->x = -1;
	if (c1->y < c2->y)
		step->y = 1;
	else
		step->y = -1;
}

void	bresenham(t_coor *c1, t_coor *c2, t_win *win)
{
	t_coor	delta;
	t_coor	step;
	t_coor	cur;
	int		err[2];

	init_delta_and_step(c1, c2, &delta, &step);
	err[0] = delta.x - delta.y;
	cur = *c1;
	while (cur.x != c2->x || cur.y != c2->y)
	{
		mlx_pixel_put(win->mlx_ptr, win->win_ptr, cur.x, cur.y,
					get_color(cur, c1, c2, delta));
		err[1] = err[0] * 2;
		if (err[1] < delta.x)
		{
			err[0] += delta.x;
			cur.y += step.y;
		}
		if (err[1] > -delta.y)
		{
			err[0] -= delta.y;
			cur.x += step.x;
		}
	}
	free(c1);
	free(c2);
}