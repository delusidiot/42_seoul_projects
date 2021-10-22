/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:36 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:05:37 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	mouse_scroll_handler(int keycode, t_win *win)
{
	if (keycode == MOUSE_UP_SCROLL)
		win->camera->zoom += 1;
	else if (keycode == MOUSE_DOWN_SCROLL)
		win->camera->zoom -= 1;
	if (win->camera->zoom < 1)
		win->camera->zoom = 1;
	return (0);
}

int	mouse_release_handler(int keycode, int x, int y, t_win *win)
{
	(void)keycode;
	(void)x;
	(void)y;
	win->mouse->flag_mb1_pressed = 0;
	win->mouse->flag_mb2_pressed = 0;
	win->mouse->flag_mb3_pressed = 0;
	return (0);
}

int	mouse_press_handler(int keycode, int x, int y, t_win *win)
{
	(void)x;
	(void)y;
	if (keycode == MOUSE_UP_SCROLL || keycode == MOUSE_DOWN_SCROLL)
		mouse_scroll_handler(keycode, win);
	else if (keycode == MOUSE_BUTTON1)
			win->mouse->flag_mb1_pressed = 1;
	else if (keycode == MOUSE_BUTTON2)
			win->mouse->flag_mb2_pressed = 1;
	else if (keycode == MOUSE_BUTTON3)
			win->mouse->flag_mb3_pressed = 1;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw_map(win);
	return (0);
}

int	mouse_move_handler(int x, int y, t_win *win)
{
	win->mouse->prev_x = win->mouse->cur_x;
	win->mouse->prev_y = win->mouse->cur_y;
	win->mouse->cur_x = x;
	win->mouse->cur_y = y;
	if (win->mouse->flag_mb1_pressed)
	{
		win->camera->x_offset += (x - win->mouse->prev_x);
		win->camera->y_offset += (y - win->mouse->prev_y);
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		draw_map(win);
	}
	else if (win->mouse->flag_mb2_pressed)
	{
		win->camera->z_magnify += (y - win->mouse->prev_y);
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		draw_map(win);
	}
	else if (win->mouse->flag_mb3_pressed)
	{
		win->camera->beta += (x - win->mouse->prev_x) * 0.005;
		win->camera->alpha += (y - win->mouse->prev_y) * 0.005;
		mlx_clear_window(win->mlx_ptr, win->win_ptr);
		draw_map(win);
	}
	return (0);
}
