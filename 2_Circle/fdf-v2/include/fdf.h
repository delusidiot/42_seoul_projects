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

# define WIN_WIDTH      1280
# define WIN_HEIGHT     720
# define CONSOL_WIDTH   300
# define MAX_ZOOM       100
# define MIN_ZOOM       1
# define MAX_Z          10
# define MIN_Z          -10
# define MAX_COLOR_NUM  4

/*
** error message
*/

# define USAGE "./fdf fdf_file\n"
# define MAP_MAKE_ERROR "map make error\n"
# define MAP_INFO_ERROR "map information error\n"
# define MAP_INSERT_ERROR "map insert error\n"

typedef struct s_value
{
	int	z;
	int	color;
}		t_value;

typedef struct s_map
{
	t_value	**values;
	int		width;
	int		height;
	int		z_max;
	int		z_min;
	int		color;
	int		default_color;
	int		isometric;
	int		flag_color;
}			t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*data;
	int		width;
	int		height;
	int		size;
	int		bpp;
	int		endian;
}			t_img;

typedef enum e_projection
{
	ISOMETRIC,
	PARALLEL
}	t_projection;

typedef struct s_camera
{
	t_projection	projection;
	double			alpha;
	double			beta;
	double			gamma;
	int				x_offset;
	int				y_offset;
	int				zoom;
	double			z_magnify;
}					t_camera;

typedef struct s_mouse
{
	int			flag_mb1_pressed;
	int			flag_mb2_pressed;
	int			flag_mb3_pressed;
	int			cur_x;
	int			cur_y;
	int			prev_x;
	int			prev_y;
}				t_mouse;

typedef struct s_keyboard
{
	int	flag_shift_pressed;
}		t_keyboard;

typedef struct s_win
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		*img;
	t_map		*map;
	t_camera	*camera;
	t_mouse		*mouse;
	t_keyboard	*keyboard;
}				t_win;

typedef struct s_step
{
	float	x_step;
	float	y_step;
}			t_step;

typedef struct s_coor
{
	int	x;
	int	y;
	int	z;
	int	color;
}		t_coor;

/*
** window control functions
*/

int		win_init(t_win *win, char *title);
void	win_free(t_win *win);
int		init_camera(t_win *win);
void	reset_camera(t_win *win);
float	float_max(float a, float b);
float	float_mod(float a);
int		int_abs(int a);
int		int_max(int a, int b);
int		int_min(int a, int b);

/*
** draw functions
*/

int		line_draw(t_win *win);
int		draw_map(t_win *win);
void	bresenham(t_coor *c1, t_coor *c2, t_win *win);
int		get_color(t_coor cur, t_coor *c1, t_coor *c2, t_coor delta);
int		get_z_color(t_coor *cur, t_win *win);
void	clean_image(t_win *win);

/*
** status printer
*/
void	print_status(t_win *win);
void	print_control(t_win *win);

/*
** map read functions
*/
void	map_free(t_win *win);
int		map_make(t_win *win);
int		map_error(char *message, t_win *win);
int		map_reader(char *filename, t_win *win);
int		map_checker(char *filename, t_win *win);
int		is_number(char *num);
int		is_hex(char *num);
int		hex_to_int(char *hex);

/*
** keyboard event functions
*/

int		key_press_handler(int keycode, t_win *win);
int		key_release_handler(int keycode, t_win *win);

/*
** mouse event functions
*/

int		mouse_release_handler(int keycode, int x, int y, t_win *win);
int		mouse_press_handler(int keycode, int x, int y, t_win *win);
int		mouse_move_handler(int x, int y, t_win *win);

/*
** error message
*/
int		put_error(char *err_msg);
void	usage(void);

#endif
