/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_gsp_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 13:47:28 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:51:07 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	check_gsp2(t_pft *pft)
{
	int i;

	i = -1;
	while (F_DEC_S + i > 0 && !pft->f_decimal[F_DEC_S + i])
		i--;
	if (i == -F_DEC_S)
		pft->exponent = 0;
	else
		pft->exponent = i;
	if (pft->exponent)
	{
		i = -1;
		while (!pft->f_decimal[F_DEC_S - 1 - ++i])
			pft->precision++;
	}
	if (pft->flags & _FSH)
		pft->precision--;
}

void	check_gsp(t_pft *pft)
{
	int i;
	int temp;

	temp = pft->precision;
	i = F_INT_S;
	while (!pft->f_integer[i] && i)
		i--;
	if (i > 0)
		pft->exponent = i;
	if (i > 0 || (i == 0 && pft->f_integer[0]))
		pft->sdig = i + 1;
	else
		pft->sdig = 0;
	if (i > 0 || (i == 0 && pft->f_integer[0]))
		pft->precision = pft->precision - pft->sdig;
	if (i == 0 && pft->f_integer[0] == 0)
		check_gsp2(pft);
	if (pft->exponent < -4 || pft->precision < 0)
		pft->sp = 'e';
	else
		pft->sp = 'f';
	if (pft->sp == 'e')
		pft->precision = temp - 1;
}
