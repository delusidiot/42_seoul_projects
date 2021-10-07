#include "fdf.h"

int num_check(char *num)
{
    int i;
    int j;
    int check;
    char *numbers;

    if (ft_strlen(num) > 1 && num[0] =='0' && (num[1] =='x' || num[1] == 'X')) // 16진수
    {
        i = 1;
        numbers = "0123456789abcdefABCDEF";
        while (num[++i]){
            j = -1;
            check = FALSE;
            while (numbers[++j]){
                if (num[i] == numbers[j])
                    check = TRUE;
            }
            if (!check)
                return (FALSE);
        }
    }
    else
    {
        i = -1;
        while (num[++i])
            if (!ft_isdigit(num[i]))
                return (FALSE);
    }
    return (TRUE);
}

int hex_to_int(char *hex)
{
    char *numbers;
    int num;
    int i;
    int j;

    i = 1;
    num = 0;
    while (hex[++i]){
        numbers = "0123456789ABCDEF";
        if (hex[i]>='a' && hex[i] <= 'z')
            numbers = "0123456789abcdef";
        j = 0;
        while (hex[i] != numbers[j])
            j++;
        num *= 16;
        num += j;
    }
    return (num);
}