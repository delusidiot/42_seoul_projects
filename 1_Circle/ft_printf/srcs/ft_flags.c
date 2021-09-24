/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flags.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:49:51 by jjeon             #+#    #+#             */
/*   Updated: 2021/05/31 18:28:13 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			flaging(int flag, t_pft *pft)
{
	pft->flags |= flag;
	return (flag);
}

int			is_flags(char *fmt, t_pft *pft)
{
	unsigned int flag;

	if (*fmt == ' ')
		flag = _FSP;
	else if (*fmt == '#')
		flag = _FSH;
	else if (*fmt == '+')
		flag = _FPL;
	else if (*fmt == '-')
		flag = _FMI;
	else if (*fmt == '0')
		flag = _FZE;
	else
		flag = 0;
	return (flaging(flag, pft));
}

char		*set_width(char *fmt, t_pft *pft, va_list ap)
{
	if (*fmt == '*')
	{
		pft->width = va_arg(ap, int);
		if (pft->width < 0)
			flaging(_FMI, pft);
		fmt++;
	}
	else
	{
		while (ft_isdigit(*fmt))
		{
			pft->width *= 10;
			pft->width += (*fmt) - '0';
			fmt++;
		}
	}
	pft->width = int_abs(pft->width);
	return (fmt);
}

char		*set_precision(char *fmt, t_pft *pft, va_list ap)
{
	int sign;

	sign = 1;
	if (*fmt == '.')
	{
		pft->precision = 0;
		fmt++;
		if (*fmt == '*')
		{
			pft->precision = va_arg(ap, int);
			return (++fmt);
		}
		if (*fmt == '-')
		{
			sign = -1;
			fmt++;
		}
		while (ft_isdigit(*fmt))
		{
			pft->precision = pft->precision * 10 + ((*fmt) - '0');
			fmt++;
		}
		pft->precision = pft->precision * sign;
	}
	return (fmt);
}

int			is_length(char *fmt, t_pft *pft)
{
	int len;

	len = 0;
	if (*fmt == 'l')
	{
		if (pft->len_mod == _L_L)
			pft->len_mod = _L_LL;
		else if (pft->len_mod == 0)
			pft->len_mod = _L_L;
		len = 'l';
	}
	else if (*fmt == 'h')
	{
		if (pft->len_mod == _L_H)
			pft->len_mod = _L_HH;
		else if (pft->len_mod == 0)
			pft->len_mod = _L_H;
		len = 'h';
	}
	return (len);
}
