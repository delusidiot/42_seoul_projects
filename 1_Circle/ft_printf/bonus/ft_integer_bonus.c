/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_integer_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:35:44 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:37:17 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int		set_signed(t_pft *pft, va_list ap)
{
	if (pft->len_mod & _L_L)
		pft->u_v.li = va_arg(ap, long int);
	else if (pft->len_mod & _L_LL)
		pft->u_v.li = va_arg(ap, long long int);
	else if (pft->len_mod & _L_H)
		pft->u_v.li = (short)va_arg(ap, int);
	else if (pft->len_mod & _L_HH)
		pft->u_v.li = (char)va_arg(ap, int);
	else
		pft->u_v.li = va_arg(ap, int);
	if (pft->u_v.li < 0)
		pft->sign = -1;
	pft->s = ft_signed_itoa(pft->u_v.li, 1, 10);
	return (1);
}

int		set_unsigned(char *fmt, t_pft *pft, va_list ap)
{
	int i;

	i = -1;
	if (pft->len_mod & _L_L)
		pft->u_v.li = va_arg(ap, unsigned long);
	else if (pft->len_mod & _L_LL)
		pft->u_v.li = va_arg(ap, unsigned long long);
	else if (pft->len_mod & _L_H)
		pft->u_v.li = (unsigned short)va_arg(ap, unsigned int);
	else if (pft->len_mod & _L_HH)
		pft->u_v.li = (unsigned char)va_arg(ap, unsigned int);
	else
		pft->u_v.li = va_arg(ap, unsigned int);
	if (*fmt == 'x' || *fmt == 'X')
		pft->s = ft_signed_itoa(pft->u_v.li, 0, 16);
	else if (*fmt == 'o')
		pft->s = ft_signed_itoa(pft->u_v.li, 0, 8);
	else
		pft->s = ft_signed_itoa(pft->u_v.li, 0, 10);
	if (*fmt == 'X')
	{
		while (pft->s[++i])
			pft->s[i] = ft_toupper(pft->s[i]);
	}
	return (1);
}

int		set_point(t_pft *pft, va_list ap)
{
	void	*addr;
	char	*str_addr;

	addr = va_arg(ap, void*);
	if (!addr && pft->precision == 0)
		str_addr = ft_strdup("");
	else if (!addr)
		str_addr = ft_strdup("0");
	else
		str_addr = ft_signed_itoa((unsigned long long)addr, 0, 16);
	pft->s = ft_strjoin("0x", str_addr);
	pft->nchar = ft_strlen(pft->s);
	if (str_addr)
		free(str_addr);
	return (1);
}
