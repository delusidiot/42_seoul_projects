/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:40 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:23:44 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

float	float_max(float a, float b)
{
	if (a > b)
		return (a);
	return (b);
}

float	float_mod(float a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	int_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

int	int_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	int_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
