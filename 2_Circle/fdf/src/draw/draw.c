#include "fdf.h"

static void	put_pixel(t_win *win, int y, int z, double uvector, int color)
{
	int		pos;

	if ((y > 0 && z > 0) && (y < WIN_WIDTH && z < WIN_HEIGHT))
	{
		pos = (y * 4) + (z * WIN_WIDTH * 4);
		// win->img->data[pos] = (color & 0xFF0000);// + uvector;
		// win->img->data[pos + 1] = (color & 0x00FF00);// + uvector;
		// win->img->data[pos + 2] = (color & 0x0000FF);// + uvector;
		win->img->data[pos] = win->color->red + uvector;
		win->img->data[pos + 1] = win->color->green + uvector;
		win->img->data[pos + 2] = win->color->blue + uvector;
		win->img->data[pos + 3] = 0x7F + uvector;
	}
}

static void	draw_lines(t_win *win, int color)
{
	double y;
	double z;
	double delta_y;
	double delta_z;
	double uvector;

	y = win->map->y0;
	z = win->map->z0;
	delta_y = win->map->y1 - win->map->y0;
	delta_z = win->map->z1 - win->map->z0;
	uvector = sqrt((pow(delta_y, 2)) + (pow(delta_z, 2)));
	delta_y /= uvector;
	delta_z /= uvector;
	while (uvector > 0)
	{
		put_pixel(win, y, z, uvector, color);
		y += delta_y;
		z += delta_z;
		uvector -= 1;
	}
}

/*
** Draw the map, depending on the angles, the zoom level, the position (defined)
** by the average value of the window size, and if the user has moved the map,
** and the x value (isometric).
** Will draw horizontal lines (y axis).
*/

static void	draw_horizontal(t_win *win, int y, int z)
{
	int		yt;
	int		zt;

	yt = y - win->map->width / 2;
	zt = z - win->map->height / 2;
	win->map->y0 = win->map->angle_y * (yt - zt) * win->map->zoom;
	win->map->z0 = win->map->angle_z * (yt + zt) * win->map->zoom;
	win->map->z0 -= win->map->values[z][y].z * win->map->x_value;
	win->map->y1 = win->map->angle_y * ((yt + 1) - zt) * win->map->zoom;
	win->map->z1 = win->map->angle_z * ((yt + 1) + zt) * win->map->zoom;
	win->map->z1 -= win->map->values[z][y + 1].z * win->map->x_value;
	win->map->y0 += (WIN_WIDTH / 2) + win->map->coordinate_y;
	win->map->y1 += (WIN_WIDTH / 2) + win->map->coordinate_y;
	win->map->z0 += (WIN_HEIGHT / 2) + win->map->coordinate_z;
	win->map->z1 += (WIN_HEIGHT / 2) + win->map->coordinate_z;
	draw_lines(win, win->map->values[y][z].color);
}

/*
** Draw the map, depending on the angles, the zoom level, the position (defined)
** by the average value of the window size, and if the user has moved the map,
** and the x value (isometric).
** Will draw vertical lines (z axis).
*/

static void	draw_vertical(t_win *win, int y, int z)
{
	int		yt;
	int		zt;

	yt = y - win->map->width / 2;
	zt = z - win->map->height / 2;
	win->map->y0 = win->map->angle_y * (yt - zt) * win->map->zoom;
	win->map->z0 = win->map->angle_z * (yt + zt) * win->map->zoom;
	win->map->z0 -= win->map->values[z][y].z * win->map->x_value;
	win->map->y1 = win->map->angle_y * (yt - (zt + 1)) * win->map->zoom;
	win->map->z1 = win->map->angle_z * (yt + (zt + 1)) * win->map->zoom;
	win->map->z1 -= win->map->values[z + 1][y].z * win->map->x_value;
	win->map->y0 += (WIN_WIDTH / 2) + win->map->coordinate_y;
	win->map->y1 += (WIN_WIDTH / 2) + win->map->coordinate_y;
	win->map->z0 += (WIN_HEIGHT / 2) + win->map->coordinate_z;
	win->map->z1 += (WIN_HEIGHT / 2) + win->map->coordinate_z;
	//printf("%d %d, %d %d, %d %d, %d %d\n", y, z, yt, zt, win->map->y0, win->map->z0, win->map->y1, win->map->z1);
	draw_lines(win, win->map->values[z][y].color);
}

/*
** Draw the map by image.
** Creates a new one, and destroys the old one whenever an action occures.
** The characters in the draw_map() function stands for:
** @h -> horizontal
** @v -> vertical
*/

int			line_draw(t_win *win)
{
	int		y;
	int		z;

	z = 0;
	win->img->img_ptr = mlx_new_image(win->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	win->img->data = mlx_get_data_addr(win->img->img_ptr,\
		&win->img->bpp, &win->img->size, &win->img->endian);
	while (win->map->height > z)
	{
		y = 0;
		while (win->map->width > y)
		{
			win->map->y0 = y;
			win->map->z0 = z;
			if (win->map->width > y + 1)
				draw_horizontal(win, y, z);
			if (win->map->height > z + 1)
				draw_vertical(win, y, z);
			y++;
		}
		z++;
	}
	mlx_put_image_to_window(win->mlx_ptr, win->win_ptr, win->img->img_ptr, 0, 0);
	mlx_destroy_image(win->mlx_ptr, win->img->img_ptr);
	return (0);
}