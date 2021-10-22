/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_release_handler.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:33 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:05:34 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_release_handler(int keycode, t_win *win)
{
	if (keycode == KEY_SHIFT)
		win->keyboard->flag_shift_pressed = 0;
	return (0);
}
