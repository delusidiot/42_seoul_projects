#include "fdf.h"

#define MAX1(a, b) (a > b ? a : b)
#define MOD(a) (a < 0 ? -a : a)

double mod(double i)
{
    return (i < 0) ? -i : i;
}

void    isometric(float *x, float *y, int z, t_win *win)
{
    *x = (*x - *y) * win->map->angle_x;
    *y = (*x + *y) * win->map->angle_y - z;
}

int     color_selector(int z)
{
    int color;

    color = 0xFF;
    if (color > 0xFF)
        color = 0xFF;
    if (color < 0)
        color = 0;
    color <<= 4;
    return color;
}

void    bresenham(float x, float y, float x1, float y1, t_win *win)
{
    float x_step;
    float y_step;
    int max;
    int z;
    int z1;
    int color;

    // ------------color-------
    z = win->map->values[(int)y][(int)x].z * win->map->magnify_z;
    z1 = win->map->values[(int)y1][(int)x1].z * win->map->magnify_z;
    color = (z || z1) ? color_selector(z) : 0xffffff;

    // -----------zoom---------
    x *= win->map->zoom;
    y *= win->map->zoom;
    x1 *= win->map->zoom;
    y1 *= win->map->zoom;
    // ===========3d==========
    // isometric(&y, &x, z, win);
    // isometric(&y1, &x1, z1, win);
    isometric(&x, &y, z, win);
    isometric(&x1, &y1, z1, win);
    // -----------shift---------
    x += win->map->shift_x;
    x1 += win->map->shift_x;
    y += win->map->shift_y;
    y1 += win->map->shift_y;

    x_step = x1 - x; // x 변위
    y_step = y1 - y; // y 변위
    max = MAX1(MOD(x_step), MOD(y_step));
    x_step /= max;
    y_step /= max;
    while ((int)(x - x1) || (int)(y - y1))
    {
        mlx_pixel_put(win->mlx_ptr, win->win_ptr, x, y, color);
        x += x_step;
        y += y_step;
    }
}

int draw_map(t_win *win)
{
    int x;
    int y;

    y = 0;
    while (y < win->map->height){
        x = 0;
        while (x < win->map->width){
            if (x < win->map->width - 1)
                bresenham(x, y, x + 1, y, win);
            if (y < win->map->height - 1)
                bresenham(x, y, x, y + 1, win);
            x++;
        }
        y++;
    }
    return (0);
}
