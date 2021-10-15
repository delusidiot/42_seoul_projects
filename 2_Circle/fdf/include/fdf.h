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
# define MAX_X		(10)
# define MAGIC_ZOOM	(2)

/*
** error message
*/
# define USAGE "./fdf fdf_file\n"
# define MAP_MAKE_ERROR "map make error\n"
# define MAP_INFO_ERROR "map information error\n"
# define MAP_INSERT_ERROR "map insert error\n"

typedef struct s_value
{
	int z;
	int color;
}	t_value;

typedef struct	s_map
{
	t_value	**values;
	int		shift_x;
	int		shift_y;
	int		width;
	int		height;
	double		magnify_z;
	double		angle_x;
	double		angle_y;
	int		zoom;
	int		isometric;
	double	x_value;
	double	angle_z;
	int	color;
	int	default_color;
}				t_map;

typedef struct	s_img
{
	void			*img_ptr;
	char			 *data;
	int			 width;
	int			 height;
	int			 size;
	int			 bpp;
	int			 endian;
}   t_img;

typedef struct s_win
{
	void	*mlx_ptr;
	void	*win_ptr;
	t_img   *img;
	t_map   *map;
} t_win;

typedef struct s_step
{
	float x_step;
	float y_step;
} t_step;

/*
** window control functions
*/

int	 win_init(t_win *win, char *title);

/*
** draw functions
*/

int			line_draw(t_win *win);
int draw_map(t_win *win);
void	bresenham(float x, float y, float x1, float y1, t_win *win);
float float_max(float a, float b);
float float_mod(float a);

/*
** map read functions
*/

int	map_init(t_win *win);
void	map_free(t_win *win);
int	map_make(t_win *win);
int	 map_error(char *message, t_win *win);
int	 map_reader(char *filename, t_win *win);
void	map_setting(t_win *win);
int map_checker(char *filename, t_win *win);
int is_number(char *num);
int is_hex(char *num);
int hex_to_int(char *hex);

/*
** keyboard event functions
*/

int key_handler(int keycode, t_win *win);

/*
** error message
*/
int put_error(char *err_msg);
void	usage();

#endif