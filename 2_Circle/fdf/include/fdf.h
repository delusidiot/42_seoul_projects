#ifndef FDF_H
# define FDF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "get_next_line.h"
# include "mlx.h"
# include "keys.h"

# define FT_PI		3.14159265358979323846

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MAX_ZOOM 5
# define MAX_X	    (10)
# define MAGIC_ZOOM	(2)

/*
** usage message
*/

# define USAGE "./fdf fdf_file\n"

/*
** error message
*/
# define MAP_READ_ERROR "map open error\n"
# define MAP_SIZE_ERROR "map size error\n"
# define MAP_COORDINATE_ERROR "map coordinate error\n"

typedef struct s_coor
{
    int z;
    int color;
}	t_coor;

typedef struct	s_map
{
	t_coor	**values;
	int		shift_x;
	int		shift_y;
	int		width;
	int		height;
	double		magnify_z;
	double		angle_x;
	double		angle_y;
	int		rotate_x;
	int		rotate_y;

	int		coordinate_y;
	int		coordinate_z;
	int		y0;
	int		y1;
	int		z0;
	int		z1;
	int		zoom;
	int		isometric;
	double	x_value;
	// double	angle_y;
	double	angle_z;
}				t_map;

typedef struct	s_img
{
	void            *img_ptr;
	char             *data;
    int             width;
    int             height;
	int             size;
	int             bpp;
	int             endian;
}   t_img;

typedef struct s_color
{
	int red;
	int green;
	int blue;
} t_color;

typedef struct s_win
{
    void    *mlx_ptr;
    void    *win_ptr;
    t_img   *img;
    t_map   *map;
	t_color	*color;
} t_win;

/*
** window control functions
*/

int     win_init(t_win *win, char *title);

/*
** draw functions
*/

int			line_draw(t_win *win);
int draw_map(t_win *win);
void    bresenham(float x, float y, float x1, float y1, t_win *win);

/*
** map read functions
*/

void    map_init(t_win *win);
void    map_free(t_win *win);
void    map_make(t_win *win);
int     map_error(char *message, t_win *win);
int     map_reader(char *filename, t_win *win);
void    map_setting(t_win *win);
int num_check(char *num);
int hex_to_int(char *hex);

/*
** keyboard event functions
*/

int key_handler(int keycode, t_win *win);

/*
** mouse event functions
*/

#endif