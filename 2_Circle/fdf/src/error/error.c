#include "fdf.h"

void    usage()
{
    write(1, USAGE, ft_strlen(USAGE));
}

void    put_error(char *err_msg){
    write(2, err_msg, ft_strlen(err_msg));
    exit(1);
}