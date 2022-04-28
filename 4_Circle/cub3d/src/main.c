/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 18:05:52 by jjeon             #+#    #+#             */
/*   Updated: 2022/04/28 18:23:22 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	window_create(t_win *win, char *title)
{
	char	*full_title;

	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (-1); // charge error code
	full_title = ft_strjoin("CUB3D - ", title);
	if (!full_title)
		return (-1); // charge error code
	win->win_ptr = mlx_new_window(win->mlx_ptr, 1000, 1000, full_title);
	if (!win->win_ptr)
		return (-1);
	free(full_title);
	return (1);
}

int main(int argc, char **argv)
{
	t_win win;
	(void)argc;
	(void)argv;
	window_create(&win, "test");
	mlx_loop(win.mlx_ptr);
	return (0);
}
