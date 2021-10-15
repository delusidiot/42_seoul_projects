#include "fdf.h"

int    key_handler(int keycode, t_win *win)
{
    if (keycode == KEY_ESCAPE)
		exit(0);
	else if (keycode == KEY_ANSI_R)
		map_setting(win);
	else if (keycode == KEY_ANSI_W)
		win->map->shift_y -= 10;
	else if (keycode == KEY_ANSI_S)
		win->map->shift_y += 10;
	else if (keycode == KEY_ANSI_D || keycode == KEY_RIGHTARROW)
		win->map->shift_x += 10;
	else if (keycode == KEY_ANSI_A || keycode == KEY_LEFTARROW)
		win->map->shift_x -= 10;
	else if (keycode == KEY_ANSI_B)
		win->map->zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (win->map->zoom > MAX_ZOOM))
		win->map->zoom -= 1;
	else if ((keycode == KEY_ANSI_J) && (win->map->magnify_z < MAX_X))
		win->map->magnify_z += 0.25;
	else if ((keycode == KEY_ANSI_K) && (win->map->magnify_z > -MAX_X))
		win->map->magnify_z -= 0.25;
    else if (keycode == KEY_UPARROW)
        win->map->rotate_x += 10;
    else if (keycode == KEY_DOWNARROW)
        win->map->rotate_x -= 10;
    else if (keycode == KEY_RIGHTARROW)
        win->map->rotate_y += 10;
    else if (keycode == KEY_LEFTARROW)
        win->map->rotate_y -= 10;
	else if (keycode == KEY_SPACE)
		win->map->angle_y *= (win->map->isometric++ % 2) ? 0.2 : 5;
    mlx_clear_window(win->mlx_ptr, win->win_ptr);
    draw_map(win);
    return (0);
}