#include "fdf.h"

void	create_window(t_win *win, char *title)
{
	win->mlx_ptr = mlx_init();
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, title);
}

int win_init(t_win *win, char *title)
{
	win->img = malloc(sizeof(t_img));
	create_window(win, title);
}