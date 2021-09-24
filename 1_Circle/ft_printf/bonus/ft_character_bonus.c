/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_character_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 20:55:31 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:35:30 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		set_percent(t_pft *pft)
{
	pft->s = ft_strdup("%");
	return ('%');
}

int		set_char(t_pft *pft, va_list ap)
{
	if (pft->len_mod & _L_L)
		pft->s = ft_chrdup(pft, va_arg(ap, unsigned int));
	else
		pft->s = ft_chrdup(pft, (unsigned char)va_arg(ap, int));
	return (1);
}

int		set_string(t_pft *pft, va_list ap)
{
	if (pft->len_mod & _L_L)
		pft->s = ft_uni_strdup(pft, va_arg(ap, unsigned int*));
	else
		pft->s = ft_strdup(va_arg(ap, char*));
	return (1);
}
