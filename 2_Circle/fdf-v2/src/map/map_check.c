/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:07 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:17:52 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int	map_init(t_win *win)
{
	win->map = NULL;
	win->map = malloc(sizeof(t_map));
	if (!win->map)
		return (FALSE);
	win->map->width = -1;
	win->map->height = 0;
	return (TRUE);
}

static int coordinate_check_error(char *err_msg, char *temp, char **z_info)
{
    int i;

    i = -1;
    while (z_info[++i])
        free(z_info[i]);
    free(temp);
    put_error(err_msg);
    return (FALSE);
}

static int map_check_error(char *err_msg, char **temp, char *line)
{
    free(temp);
    free(line);
    put_error(err_msg);
    return (FALSE);
}

static int	coordinate_check(char *temp)
{
	int		i;
	char	**z_info;

	z_info = ft_split(temp, ',');
	i = -1;
	if (!is_number(z_info[0]))
		return (coordinate_check_error("is not number\n", temp, z_info));
	if (z_info[1] && !is_hex(z_info[1]))
		return (coordinate_check_error("is not hex\n", temp, z_info));
	i = -1;
	while (z_info[++i])
		free(z_info[i]);
	free(z_info);
	free(temp);
	return (TRUE);
}

int	map_checker(char *filename, t_win *win)
{
	int		i;
	int		fd;
	char	*line;
	char	**temp;

	fd = open(filename, O_RDONLY);
	if (!map_init(win) || fd < 0)
		return (put_error("file or init\n"));
	while (get_next_line(fd, &line))
	{
		i = -1;
		temp = ft_split(line, ' ');
		while (temp[++i])
			if (!coordinate_check(temp[i]))
				return (map_check_error("coordinate_check\n", temp, line));
		free(temp);
		free(line);
		if (win->map->width != -1 && i != win->map->width)
			return (put_error("width\n"));
		win->map->width = i;
		win->map->height++;
	}
	free(line);
	close(fd);
	return (TRUE);
}
