#include "fdf.h"

static double	get_ratio(int c1, int c2, int cur)
{
	double	ratio;

	if (c2 == c1)
		return (1.0);
	ratio = (double)(cur - c1) / (c2 - c1);
	return (ratio);
}

int	get_default_color(int z, t_map *map)
{
	double	ratio;

	ratio = get_ratio(map->z_min, map->z_max, z);
	if (ratio < 0.2)
		return (0x9A1F6A);
	else if (ratio < 0.4)
		return (0xC2294E);
	else if (ratio < 0.6)
		return (0xEC4B27);
	else if (ratio < 0.8)
		return (0xEF8633);
	else
		return (0xF3AF3D);
}

static int	do_lerp(int c1, int c2, double ratio)
{
	return ((int)((ratio) * c1 + (1 - ratio) * c2));
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