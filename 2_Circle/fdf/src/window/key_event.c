#include "fdf.h"

void	move_key_handler(int keycode, t_win *win)
{
	if (keycode == KEY_ANSI_W)
		win->map->shift_y -= 10;
	else if (keycode == KEY_ANSI_S)
		win->map->shift_y += 10;
	else if (keycode == KEY_ANSI_D || keycode == KEY_RIGHTARROW)
		win->map->shift_x += 10;
	else if (keycode == KEY_ANSI_A || keycode == KEY_LEFTARROW)
		win->map->shift_x -= 10;
}

void	map_control_handler(int keycode, t_win *win)
{
	if (keycode == KEY_ANSI_B)
		win->map->zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (win->map->zoom > MAX_ZOOM))
		win->map->zoom -= 1;
	else if ((keycode == KEY_ANSI_J) && (win->map->magnify_z < MAX_X))
		win->map->magnify_z += 0.25;
	else if ((keycode == KEY_ANSI_K) && (win->map->magnify_z > -MAX_X))
		win->map->magnify_z -= 0.25;
}

void	extra_projection_handler(int keycode, t_win *win)
{
	if (keycode == KEY_SPACE)
	{
		if (win->map->isometric++ % 2)
		{
			win->map->angle_x = 0;
			win->map->angle_y = 0;
			win->map->angle_z = 0;
		}
		else
		{
			win->map->angle_x = cos(M_PI / 3);
			win->map->angle_y = cos(M_PI / 3);
			win->map->angle_z = win->map->angle_y * sin(M_PI / 6);
		}
	}
}

void	default_color_handler(int keycode, t_win *win)
{
	if (keycode == KEY_ANSI_C)
	{
		win->map->color++;
		if (win->map->color % 4 == 1)
			win->map->default_color = 0xFFFFFF;
		else if(win->map->color % 4 == 2)
			win->map->default_color = 0xFF0000;
		else if(win->map->color % 4 == 3)
			win->map->default_color = 0xFF00;
		else
			win->map->default_color = 0xFF;
	}
}

int	key_handler(int keycode, t_win *win)
{
	move_key_handler(keycode, win);
	map_control_handler(keycode, win);
	extra_projection_handler(keycode, win);
	default_color_handler(keycode, win);
	if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		map_setting(win);
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw_map(win);
	return (0);
}