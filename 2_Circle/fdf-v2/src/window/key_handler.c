/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:29 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:25:24 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	move_key_handler(int keycode, t_win *win)
{
	if (keycode == KEY_ANSI_W || keycode == KEY_UPARROW)
		win->camera->y_offset -= 10;
	else if (keycode == KEY_ANSI_S || keycode == KEY_DOWNARROW)
		win->camera->y_offset += 10;
	else if (keycode == KEY_ANSI_D || keycode == KEY_RIGHTARROW)
		win->camera->x_offset += 10;
	else if (keycode == KEY_ANSI_A || keycode == KEY_LEFTARROW)
		win->camera->x_offset -= 10;
}

static void	map_control_handler(int keycode, t_win *win)
{
	if (keycode == KEY_ANSI_B && (win->camera->zoom < MAX_ZOOM))
		win->camera->zoom += 1;
	else if ((keycode == KEY_ANSI_N) && (win->camera->zoom > MIN_ZOOM))
		win->camera->zoom -= 1;
	else if ((win->camera->z_magnify < MAX_Z) && (keycode == KEY_ANSI_J))
		win->camera->z_magnify += 1;
	else if ((win->camera->z_magnify > MIN_Z) && (keycode == KEY_ANSI_K))
		win->camera->z_magnify -= 1;
	else if ((keycode == KEY_ANSI_X) && !win->keyboard->flag_shift_pressed)
		win->camera->alpha += 0.03;
	else if ((keycode == KEY_ANSI_Y) && !win->keyboard->flag_shift_pressed)
		win->camera->beta += 0.03;
	else if ((keycode == KEY_ANSI_Z) && !win->keyboard->flag_shift_pressed)
		win->camera->gamma += 0.03;
	else if ((keycode == KEY_ANSI_X) && win->keyboard->flag_shift_pressed)
		win->camera->alpha -= 0.03;
	else if ((keycode == KEY_ANSI_Y) && win->keyboard->flag_shift_pressed)
		win->camera->beta -= 0.03;
	else if ((keycode == KEY_ANSI_Z) && win->keyboard->flag_shift_pressed)
		win->camera->gamma -= 0.03;
}

static void	extra_projection_handler(int keycode, t_win *win)
{
	if (keycode == KEY_SPACE)
	{
		win->camera->alpha = 0;
		win->camera->beta = 0;
		win->camera->gamma = 0;
		if (win->map->isometric++ % 2)
			win->camera->projection = ISOMETRIC;
		else
			win->camera->projection = PARALLEL;
	}
}

static void	default_color_handler(int keycode, t_win *win)
{
	if (keycode == KEY_ANSI_C)
	{
		win->map->color++;
		if (win->map->color % 4 == 1)
			win->map->default_color = 0xFF0000;
		else if (win->map->color % 4 == 2)
			win->map->default_color = 0xFF00;
		else if (win->map->color % 4 == 3)
			win->map->default_color = 0xFF;
		else
			win->map->default_color = 0xFFFFFF;
		if (win->map->color % 8 == 4 || win->map->color % 8 == 5
			|| win->map->color % 8 == 6 || win->map->color % 8 == 7)
			win->map->flag_color = 1;
		else
			win->map->flag_color = 0;
	}
}

int	key_press_handler(int keycode, t_win *win)
{
	move_key_handler(keycode, win);
	map_control_handler(keycode, win);
	extra_projection_handler(keycode, win);
	default_color_handler(keycode, win);
	if (keycode == KEY_ESCAPE)
	{
		win_free(win);
		map_free(win);
		exit(0);
	}
	else if (keycode == KEY_ANSI_R)
		reset_camera(win);
	else if (keycode == KEY_SHIFT)
		win->keyboard->flag_shift_pressed = 1;
	mlx_clear_window(win->mlx_ptr, win->win_ptr);
	draw_map(win);
	return (0);
}
