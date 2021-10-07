#include "fdf.h"

int key_handler(int keycode, t_win *win)
{
    if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		map_setting(win);
	else if (keycode == KEY_ANSI_W || keycode == KEY_UPARROW)
		win->map->coordinate_z -= 1;
	else if (keycode == KEY_ANSI_S || keycode == KEY_DOWNARROW)
		win->map->coordinate_z += 1;
	else if (keycode == KEY_ANSI_D || keycode == KEY_RIGHTARROW)
		win->map->coordinate_y -= 1;
	else if (keycode == KEY_ANSI_A || keycode == KEY_LEFTARROW)
		win->map->coordinate_y += 1;
	else if (keycode == KEY_ANSI_B)
		win->map->zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (win->map->zoom > MAX_ZOOM))
		win->map->zoom -= 1;
	else if ((keycode == KEY_ANSI_J) && (win->map->x_value < MAX_X))
		win->map->x_value += 0.25;
	else if ((keycode == KEY_ANSI_K) && (win->map->x_value > -MAX_X))
		win->map->x_value -= 0.25;
	else if (keycode == KEY_SPACE)
		win->map->angle_z *= (win->map->isometric++ % 2) ? 0.2 : 5;
    return (0);
}