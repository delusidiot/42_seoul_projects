/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_create.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:11 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:16:45 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	map_setting(t_win *win)
{
	win->map->z_max = -2147483648;
	win->map->z_min = 2147483647;
	win->map->color = 0;
	win->map->default_color = 0xFFFFFF;
	win->map->isometric = 0;
	win->map->flag_color = 0;
}

int	map_make(t_win *win)
{
	int	i;

	i = -1;
	win->map->values = malloc(sizeof(t_value *) *(win->map->height));
	if (!win->map->values)
		return (FALSE);
	while (++i < win->map->height)
		win->map->values[i] = NULL;
	map_setting(win);
	return (TRUE);
}

void	map_free(t_win *win)
{
	int	i;

	i = -1;
	if (!win->map)
		return ;
	if (win->map->values)
	{
		while (++i < win->map->height && win->map->values[i])
			free(win->map->values[i]);
		free(win->map->values);
		win->map->values = NULL;
	}
	free(win->map);
	win->map = NULL;
}

int	map_error(char *message, t_win *win)
{
	map_free(win);
	write(2, message, ft_strlen(message));
	return (FALSE);
}
