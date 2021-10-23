/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:04:51 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:29:19 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_coor	*init_coor(int x, int y, t_win *win)
{
	t_coor	*coor;

	coor = (t_coor *)malloc(sizeof(t_coor));
	if (!coor)
		return (NULL);
	coor->x = x;
	coor->y = y;
	coor->z = win->map->values[y][x].z;
	if (win->map->flag_color)
		coor->color = get_z_color(coor, win);
	else if (win->map->values[y][x].color)
		coor->color = win->map->values[y][x].color;
	else
		coor->color = win->map->default_color;
	return (coor);
}

void	rotate_coordinate(t_coor *c, t_win *win)
{
	t_coor	prev;

	prev.x = c->x;
	prev.y = c->y;
	prev.z = c->z;
	c->y = prev.y * cos(win->camera->alpha) + c->z * sin(win->camera->alpha);
	c->z = -prev.y * sin(win->camera->alpha) + c->z * cos(win->camera->alpha);
	c->x = prev.x * cos(win->camera->beta) + (c->z) * sin(win->camera->beta);
	c->z = -prev.x * sin(win->camera->beta) + (c->z) * cos(win->camera->beta);
	c->x = prev.x * cos(win->camera->gamma) - prev.y * sin(win->camera->gamma);
	c->y = prev.x * sin(win->camera->gamma) + prev.y * cos(win->camera->gamma);
}

void	isometric(t_coor *coor)
{
	t_coor	prev;

	prev.x = coor->x;
	prev.y = coor->y;
	coor->x = (prev.x - prev.y) * cos(M_PI / 6);
	coor->y = (prev.x + prev.y) * sin(M_PI / 6) - coor->z;
}

t_coor	*setting_coordinate(t_coor *c, t_win *win)
{
	c->x *= win->camera->zoom;
	c->y *= win->camera->zoom;
	c->z *= win->camera->z_magnify;
	c->x -= (win->map->width * win->camera->zoom) / 2;
	c->y -= (win->map->height * win->camera->zoom) / 2;
	rotate_coordinate(c, win);
	if (win->camera->projection == ISOMETRIC)
		isometric(c);
	c->x += WIN_WIDTH / 2 + win->camera->x_offset;
	c->y += WIN_HEIGHT / 2 + win->camera->y_offset + \
			win->map->height * win->camera->zoom * 2 / 5;
	return (c);
}

int	draw_map(t_win *win)
{
	int	x;
	int	y;

	y = 0;
	while (y < win->map->height)
	{
		x = 0;
		while (x < win->map->width)
		{
			if (x < win->map->width - 1)
				bresenham(setting_coordinate(init_coor(x, y, win), win),
					setting_coordinate(init_coor(x + 1, y, win), win), win);
			if (y < win->map->height - 1)
				bresenham(setting_coordinate(init_coor(x, y, win), win),
					setting_coordinate(init_coor(x, y + 1, win), win), win);
			x++;
		}
		y++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img_ptr, 0, 0);
	print_control(win);
	print_status(win);
	return (0);
}
