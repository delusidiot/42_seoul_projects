/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_integer.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:01:38 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:58:47 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	integer_fix(t_pft *pft, int j)
{
	pft->f_integer[j] -= 10;
	pft->f_integer[j + 1]++;
}

void	set_floating_integer2(int ibox[F_INT_S * 2 - 1],
		int ibit[F_DEC_S], t_pft *pft)
{
	int i;
	int j;

	i = -1;
	while (++i < F_DEC_S)
	{
		if (ibit[i])
		{
			j = F_INT_S;
			while (--j >= 0)
				if ((pft->f_integer[j] += ibox[j]) > 9)
					integer_fix(pft, j);
		}
		j = F_INT_S;
		while (--j >= 0)
		{
			if ((ibox[j] *= 2) > 9)
			{
				ibox[j] -= 10;
				ibox[j + 1]++;
			}
		}
	}
}

void	set_floating_integer(unsigned long long mantissa,
		int exponent, t_pft *pft)
{
	int	ibox[F_INT_S * 2 - 1];
	int ibit[F_DEC_S];
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < F_INT_S * 2 - 1)
	{
		ibox[i] = 0;
		ibit[i++] = 0;
	}
	while (i < F_DEC_S)
		ibit[i++] = 0;
	ibox[0] = 1;
	i = 52 - exponent;
	while (i < 53)
	{
		if (i >= 0)
			ibit[j] = 1 & (mantissa >> i);
		i++;
		j++;
	}
	set_floating_integer2(ibox, ibit, pft);
}
