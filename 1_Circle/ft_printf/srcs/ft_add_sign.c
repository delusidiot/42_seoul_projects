/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_add_sign.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 10:21:08 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 16:42:47 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*set_sharp(t_pft *pft)
{
	char	*prev;
	char	*temp;

	if ((pft->sp == 'x' || pft->sp == 'X') && *(pft->s) && *(pft->s) != '0')
		pft->u_sign = 1;
	if (pft->sp == 'o' && *(pft->s) != '0')
		prev = ft_strdup("0");
	else if (pft->sp == 'x' && pft->u_sign)
		prev = ft_strdup("0x");
	else if (pft->sp == 'X' && pft->u_sign)
		prev = ft_strdup("0X");
	else
		return (pft->s);
	temp = pft->s;
	pft->s = ft_strjoin(prev, temp);
	if (prev)
		free(prev);
	if (temp)
		free(temp);
	return (pft->s);
}

char	*set_plus(t_pft *pft)
{
	char *temp;
	char *sign;

	if (pft->flags & _FPL)
		sign = "+";
	else
		sign = " ";
	temp = pft->s;
	pft->s = ft_strjoin(sign, temp);
	if (temp)
		free(temp);
	return (pft->s);
}
