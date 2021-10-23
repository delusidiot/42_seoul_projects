/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:43 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:05:44 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int main(int argc, char **argv)
{
	t_win win;

	win.map = NULL;
	if (argc == 2 && map_reader(argv[argc - 1], &win)){
		win_init(&win, argv[argc - 1]);
		draw_map(&win);
		mlx_hook(win.win_ptr, KEY_PRESS, KEY_PRESS_MASK, key_press_handler, &win);
		mlx_hook(win.win_ptr, KEY_RELEASE, KEY_RELEASE_MASK, key_release_handler, &win);
		mlx_hook(win.win_ptr, MOUSE_PRESS, BUTTON_PRESS_MASK, mouse_press_handler, &win);
		mlx_hook(win.win_ptr, MOUSE_RELEASE, BUTTON_RELEASE_MASK, mouse_release_handler, &win);
		mlx_hook(win.win_ptr, MOUSE_MOVE, POINTER_MOTION_MASK, mouse_move_handler, &win);
		mlx_loop(win.mlx_ptr);
	}
	else
		usage();
    map_free(win);
	return (0);
}
