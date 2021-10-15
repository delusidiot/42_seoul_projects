#include "fdf.h"

int main(int argc, char **argv)
{
	t_win win;
	if (argc == 2 && map_reader(argv[argc - 1], &win)){
		win_init(&win, argv[argc - 1]);
		mlx_key_hook(win.win_ptr, key_handler, &win);
		mlx_loop_hook(win.mlx_ptr, draw_map, &win);
		mlx_loop(win.mlx_ptr);
	}
	else
		usage();
	map_free(&win);
	return (0);
}