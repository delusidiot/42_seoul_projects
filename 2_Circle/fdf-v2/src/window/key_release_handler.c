#include "fdf.h"

int	key_release_handler(int keycode, t_win *win)
{
	if (keycode == KEY_SHIFT)
		win->keyboard->flag_shift_pressed = 0;
	return (0);
}