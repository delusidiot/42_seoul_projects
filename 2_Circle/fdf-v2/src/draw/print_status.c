/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_status.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:04:56 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/24 09:19:41 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	print_control(t_win *win)
{
	int	x;
	int	y;

	x = 15;
	y = 0;
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 20, 0xFFFFFF, "<Controls>");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "key W/A/S/D : move");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "key B/N : zoom");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "key J/K : z_magnify");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "key space : projection");
}

static int	print_map_setting(int x, int y, t_win *win)
{
	char	buf[10];

	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "x_offset: ");
	sprintf(buf, "%d", win->camera->x_offset);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%d", win->camera->y_offset);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "y_offset: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%d", win->camera->zoom);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "zoom: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->z_magnify);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "z_magnify: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	return (y);
}

static int	print_rotate_setting(int x, int y, t_win *win)
{
	char	buf[10];

	sprintf(buf, "%f", win->camera->alpha);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "alpa: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->beta);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "beta: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	sprintf(buf, "%f", win->camera->gamma);
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 30, 0xFFFFFF, "gamma: ");
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		120, y += 0, 0xFFFFFF, buf);
	return (y);
}

void	print_status(t_win *win)
{
	int		x;
	int		y;
	char	buf[10];

	x = 15;
	y = 150;
	mlx_string_put(win->mlx_ptr, win->win_ptr,
		x, y += 60, 0xFFFFFF, "<Status>");
	y = print_map_setting(x, y, win);
	y = print_rotate_setting(x, y, win);
}
