/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_window.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:26 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:23:03 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	window_create(t_win *win, char *title)
{
	char	*full_title;

	win->mlx_ptr = mlx_init();
	if (!win->mlx_ptr)
		return (put_error("mlx_init error"));
	full_title = ft_strjoin("fdf - ", title);
	if (!full_title)
		return (put_error("title make error"));
	win->win_ptr = mlx_new_window(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			full_title);
	if (!win->win_ptr)
		return (put_error("win create error"));
	win->img->img_ptr = mlx_new_image(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!win->img->img_ptr)
		return (put_error("image create error"));
	win->img->data = mlx_get_data_addr(win->img->img_ptr, &(win->img->bpp),
			&(win->img->size), &(win->img->endian));
	free(full_title);
	return (TRUE);
}

static int	window_create_error(t_win *win)
{
	map_free(win);
	win_free(win);
	return (put_error("window_create_error"));
}

static void	keyboard_mouse_init(t_win *win)
{
	win->mouse->flag_mb1_pressed = 0;
	win->mouse->flag_mb2_pressed = 0;
	win->mouse->flag_mb3_pressed = 0;
	win->keyboard->flag_shift_pressed = 0;
}

void	win_free(t_win *win)
{
	if (win->img->img_ptr)
		mlx_destroy_image(win->mlx_ptr, win->img->img_ptr);
	if (win->win_ptr)
		mlx_destroy_window(win->mlx_ptr, win->win_ptr);
	if (win->mlx_ptr)
		mlx_destroy_display(win->mlx_ptr);
	if (win->img)
		free(win->img);
	if (win->camera)
		free(win->camera);
	if (win->mouse)
		free(win->mouse);
	if (win->keyboard)
		free(win->keyboard);
}

int	win_init(t_win *win, char *title)
{
	win->img = malloc(sizeof(t_img));
	if (!win->img)
		return (window_create_error(win));
	if (!init_camera(win))
		return (window_create_error(win));
	if (!window_create(win, title))
		return (window_create_error(win));
	win->mouse = (t_mouse *)malloc(sizeof(t_mouse));
	if (!win->mouse)
		return (window_create_error(win));
	win->keyboard = (t_keyboard *)malloc(sizeof(t_keyboard));
	if (!win->keyboard)
		return (window_create_error(win));
	keyboard_mouse_init(win);
	return (TRUE);
}
