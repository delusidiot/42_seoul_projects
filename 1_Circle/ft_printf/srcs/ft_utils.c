/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 15:00:20 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/03 08:48:21 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		int_min(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

int		int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int		int_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}
