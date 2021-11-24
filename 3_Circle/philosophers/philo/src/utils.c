#include "philo.h"

int philo_atoi(char *str)
{
    long deca;
    int i;

    i = -1;
    deca = 0;
    while (str[++i])
        deca += (str[i] - '0') + deca * 10;
    if (deca > 2147483647)
        return _ERROR;
    return (int)deca;
}