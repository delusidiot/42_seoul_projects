/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_decimal.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:09:52 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/03 05:50:25 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	decimal_fix(t_pft *pft, int j)
{
	pft->f_decimal[j] -= 10;
	pft->f_decimal[j + 1]++;
}

void	set_floating_decimal2(int dbox[F_DEC_S], int dbit[F_DEC_S], t_pft *pft)
{
	int i;
	int j;

	i = F_DEC_S;
	while (--i >= 0)
	{
		if (dbit[i])
		{
			j = 0;
			while (++j < F_DEC_S)
				if ((pft->f_decimal[j] += dbox[j]) > 9)
					decimal_fix(pft, j);
		}
		j = 0;
		while (++j < F_DEC_S)
		{
			if (dbox[j] % 2)
				dbox[j - 1] += 5;
			dbox[j] /= 2;
		}
	}
}

void	set_floating_decimal(unsigned long long mantissa,
		int exponent, t_pft *pft)
{
	int dbox[F_DEC_S];
	int dbit[F_DEC_S];
	int i;
	int j;

	i = 0;
	while (i < F_DEC_S)
	{
		dbox[i] = 0;
		dbit[i++] = 0;
	}
	dbox[F_DEC_S - 1] = 5;
	i = 52 - exponent;
	j = 0;
	while (--i >= 0)
	{
		if (i < 53)
			dbit[F_DEC_S - 1 - j] = 1 & (mantissa >> i);
		j++;
	}
	set_floating_decimal2(dbox, dbit, pft);
}
