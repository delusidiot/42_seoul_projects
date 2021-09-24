/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_type_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 08:52:48 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:37:10 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	set_floting_type(unsigned long long mantissa, t_pft *pft)
{
	if (!(mantissa & (((1ULL << 52) - 1))) && pft->sign >= 0)
		pft->f_type |= _INF;
	else if (!(mantissa & (((1ULL << 52) - 1))) && pft->sign < 0)
		pft->f_type |= _M_INF;
	else
	{
		pft->f_type |= _NAN;
		pft->flags &= ~(_FPL | _FSP);
	}
	if (pft->flags & _FZE)
		pft->flags &= ~_FZE;
	pft->precision = 3;
}

int		is_float_type(t_pft *pft)
{
	if (pft->s)
		free(pft->s);
	if (pft->f_type & _INF)
		pft->s = ft_strdup("inf");
	else if (pft->f_type & _M_INF)
		pft->s = ft_strdup("-inf");
	else if (pft->f_type & _NAN)
		pft->s = ft_strdup("nan");
	return (1);
}
