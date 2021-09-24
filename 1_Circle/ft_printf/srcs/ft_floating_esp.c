/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_esp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:07:47 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:49:07 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_exponent_tail(t_pft *pft, char sp)
{
	int j;

	if (pft->f_integer[1])
	{
		if (sp == 'g')
			pft->sp = 'e';
		pft->exponent++;
		j = -1;
		while (1 + ++j < F_DEC_S)
			pft->f_decimal[j] = pft->f_decimal[1 + j];
		pft->f_decimal[F_DEC_S - 1] = pft->f_integer[0];
		pft->f_integer[0] = pft->f_integer[1];
		pft->f_integer[1] = 0;
	}
}

void	check_esp2(t_pft *pft)
{
	int i;
	int j;

	i = -1;
	while (F_DEC_S + i > 0 && !pft->f_decimal[F_DEC_S + i])
		i--;
	if (i == -F_DEC_S)
		pft->exponent = 0;
	else
		pft->exponent = i;
	pft->f_integer[0] = pft->f_decimal[F_DEC_S + i];
	j = 0;
	while (F_DEC_S + i + --j >= 0)
		pft->f_decimal[F_DEC_S + j] = pft->f_decimal[F_DEC_S + i + j];
}

void	check_esp(t_pft *pft)
{
	int i;
	int j;
	int k;

	i = F_INT_S;
	while (!pft->f_integer[i] && i)
		i--;
	if (i > 0)
	{
		pft->exponent = i;
		j = -1;
		while (i + ++j < F_DEC_S)
			pft->f_decimal[j] = pft->f_decimal[i + j];
		k = -1;
		while (j + ++k < F_DEC_S)
		{
			pft->f_decimal[j + k] = pft->f_integer[k];
			pft->f_integer[k] = 0;
		}
		pft->f_integer[0] = pft->f_integer[k];
		pft->f_integer[k] = 0;
	}
	if (i == 0 && pft->f_integer[0] == 0)
		check_esp2(pft);
}
