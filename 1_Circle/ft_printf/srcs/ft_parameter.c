/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parameter.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 04:37:00 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/03 07:07:29 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	init(t_pft *pft)
{
	int i;

	i = 0;
	pft->width = 0;
	pft->precision = -1;
	pft->flags = 0;
	pft->len_mod = 0;
	pft->sp = 0;
	pft->s = NULL;
	pft->f_type = 0;
	pft->sign = 1;
	pft->u_sign = 0;
	pft->unicode_size = 0;
	pft->exponent = 0;
	while (i < F_INT_S)
	{
		pft->f_integer[i] = 0;
		pft->f_decimal[i++] = 0;
	}
	while (i < F_DEC_S)
		pft->f_decimal[i++] = 0;
}

char		*parse_format(char *fmt, t_pft *pft, va_list ap)
{
	init(pft);
	while (is_flags(fmt, pft))
		fmt++;
	fmt = set_width(fmt, pft, ap);
	fmt = set_precision(fmt, pft, ap);
	while (is_length(fmt, pft))
		fmt++;
	if (!specifier(fmt, pft, ap))
		return (NULL);
	return (fmt);
}

int			printf_format(const char *format, va_list ap)
{
	t_pft	pft;
	char	*fmt;

	if (!format)
		return (0);
	fmt = (char *)format;
	pft.len = 0;
	while (*fmt)
	{
		pft.nchar = 1;
		if (*fmt == '%')
			fmt = parse_format(fmt + 1, &pft, ap);
		else
			write(1, fmt, 1);
		if (!fmt)
			return (_ERROR);
		pft.len += (int)pft.nchar;
		fmt++;
	}
	return (pft.len);
}
