/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:04:47 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/24 09:06:46 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double	get_ratio(int c1, int c2, int cur)
{
	double	ratio;

	if (c2 == c1)
		return (1.0);
	ratio = (double)(cur - c1) / (c2 - c1);
	return (ratio);
}

static int	do_lerp(int c2, int c1, double ratio)
{
	return ((int)((ratio) * c2 + (1 - ratio) * c1));
}

int	get_color(t_coor cur, t_coor *c1, t_coor *c2, t_coor delta)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	if (cur.color == c2->color)
		return (cur.color);
	if (delta.x > delta.y)
		ratio = get_ratio(c1->x, c2->x, cur.x);
	else
		ratio = get_ratio(c1->y, c2->y, cur.y);
	red = do_lerp((c2->color >> 16) & 0xFF, (c1->color >> 16) & 0xFF, ratio);
	green = do_lerp((c2->color >> 8) & 0xFF, (c1->color >> 8) & 0xFF, ratio);
	blue = do_lerp(c2->color & 0xFF, c1->color & 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}

int	get_z_color(t_coor *cur, t_win *win)
{
	double	ratio;
	int		red;
	int		green;
	int		blue;

	ratio = get_ratio(win->map->z_min, win->map->z_max, cur->z);
	red = do_lerp((win->map->default_color >> 16) & 0xFF, 0xFF, ratio);
	green = do_lerp((win->map->default_color >> 8) & 0xFF, 0xFF, ratio);
	blue = do_lerp(win->map->default_color & 0xFF, 0xFF, ratio);
	return ((red << 16) | (green << 8) | blue);
}
