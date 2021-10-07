#include "fdf.h"

int coorditate_check(char *temp){
    int i;
    char **z_info;

    z_info = ft_split(temp, ',');
    i = -1;
    if (!num_check(z_info[0]))
        return (FALSE);
    if (z_info[1] && !num_check(z_info[1]))
        return (FALSE);
    i = -1;
    while (z_info[++i])
        free(z_info[i]);
    free(z_info);
    return (TRUE);
}

int map_check(int fd, char *filename, t_win *win)
{
    int i;
    int j;
    char *line;
    char **temp;
    char **z_info;

    while (get_next_line(fd, &line))
    {
        i = -1;
        temp = ft_split(line, ' ');
        while (temp[++i])
        {
            coorditate_check(temp[i]);
            free(temp[i]);
        }
        free(temp);
        free(line);
        if (win->map->width != -1 && i != win->map->width)
            return (_ERROR);
        win->map->width = i;
        win->map->height++;
    }
    close(fd);
    return (TRUE);
}

int coordinate_insert(int i, char **temp, t_win *win){
    int j;
    int k;
    int l;
    char **z_info;

    j = -1;
    while (temp[++j])
    {
        z_info = ft_split(temp[j], ',');
        win->map->values[i][j].z = ft_atoi(z_info[0]);
        win->map->values[i][j].color = 0xFFFFFF;
        k = 1;
        if (z_info[1])
            win->map->values[i][j].color = hex_to_int(z_info[1]);
        free(temp[j]);
    }
}

int map_reader(char *filename, t_win *win)
{
    char *line;
    char **temp;
    int i;
    int j;
    int fd;

    map_init(win);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return map_error(MAP_READ_ERROR, win);
    if (map_check(fd, filename, win) < 0)      
        return map_error(MAP_SIZE_ERROR, win);
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return map_error(MAP_READ_ERROR, win);
    map_make(win);
    i = 0;
    while (get_next_line(fd, &line))
    {   
        win->map->values[i] = malloc(sizeof(t_coor *) * win->map->width);
        if (!win->map->values[i]){
            map_free(win);
            return (FALSE);
        }
        temp = ft_split(line, ' ');
        free(line);
        coordinate_insert(i, temp, win);
        i++;
        free(temp);
    }
    close(fd);
    map_setting(win);
    printf("%d %d\n", win->map->height, win->map->width);
    for(i = 0; i<win->map->height; i++){
        for(j = 0; j<win->map->width; j++)
            printf("%d,%#X ", win->map->values[i][j].z, win->map->values[i][j].color);
        printf("\n");
    }
    return (TRUE);
}