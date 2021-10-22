/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:01 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:05:04 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void    usage()
{
    write(1, USAGE, ft_strlen(USAGE));
}

int put_error(char *err_msg)
{
    write(2, err_msg, ft_strlen(err_msg));
    return (FALSE);
}
