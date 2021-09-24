/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_round.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 09:25:44 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:49:43 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	round_over_five(t_pft *pft)
{
	pft->f_decimal[F_DEC_S - 1 - pft->precision] = 0;
	if (pft->precision)
		pft->f_decimal[F_DEC_S - pft->precision]++;
	else
		pft->f_integer[0]++;
}

void	round_is_five(t_pft *pft)
{
	int j;

	pft->f_decimal[F_DEC_S - 1 - pft->precision] = 0;
	if (pft->precision == 0 && pft->f_integer[0] % 2)
		pft->f_integer[0]++;
	else if (pft->precision && (pft->f_decimal[F_DEC_S - pft->precision] % 2))
		pft->f_decimal[F_DEC_S - pft->precision]++;
	else
	{
		j = F_DEC_S - 1;
		while (j > pft->precision && !pft->f_decimal[F_DEC_S - 1 - j])
			j--;
		if (j != pft->precision)
		{
			if (pft->precision == 0)
				pft->f_integer[0]++;
			else
				pft->f_decimal[F_DEC_S - pft->precision]++;
		}
	}
}

void	round_moveup(t_pft *pft, int j)
{
	while (++j < F_DEC_S - 1)
	{
		if (pft->f_decimal[j] > 9)
		{
			pft->f_decimal[j] -= 10;
			pft->f_decimal[j + 1]++;
		}
	}
	if (pft->f_decimal[F_DEC_S - 1] > 9
			|| (pft->precision == 0 && pft->f_decimal[F_DEC_S - 1] > 5))
	{
		pft->f_decimal[F_DEC_S - 1] -= 10;
		pft->f_integer[0]++;
	}
	j = -1;
	while (++j < F_INT_S)
	{
		if (pft->f_integer[j] > 9)
		{
			pft->f_integer[j] -= 10;
			pft->f_integer[j + 1]++;
		}
	}
}

void	set_round(t_pft *pft)
{
	if (pft->f_decimal[F_DEC_S - 1 - pft->precision] > 5)
		round_over_five(pft);
	if (pft->f_decimal[F_DEC_S - 1 - pft->precision] == 5)
		round_is_five(pft);
	round_moveup(pft, -1);
}
