/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/24 15:11:57 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/06 19:43:38 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		set_length(t_pft *pft, va_list ap)
{
	char		*hhaddr;
	short		*haddr;
	int			*addr;
	long		*laddr;
	long long	*lladdr;

	if (pft->len_mod & _L_L)
		if (!!(laddr = va_arg(ap, long*)))
			*laddr = pft->len;
	if (pft->len_mod & _L_LL)
		if (!!(lladdr = va_arg(ap, long long*)))
			*lladdr = pft->len;
	if (pft->len_mod & _L_H)
		if (!!(haddr = va_arg(ap, short*)))
			*haddr = pft->len;
	if (pft->len_mod & _L_HH)
		if (!!(hhaddr = va_arg(ap, char*)))
			*hhaddr = pft->len;
	if (pft->len_mod == 0)
		if (!!(addr = va_arg(ap, int*)))
			*addr = (int)pft->len;
	pft->nchar = 0;
	return (1);
}

void	set_prev(t_pft *pft, long *curr_len, long *show)
{
	if (is_num(pft->sp) && !is_floating(pft->sp)
			&& pft->precision == 0 && !ft_strncmp(pft->s, "0\0", 2))
		*(pft->s) = '\0';
	if (pft->flags & _FSH)
		pft->s = set_sharp(pft);
	if ((pft->flags & (_FPL | _FSP)) && pft->sign >= 0 && is_num(pft->sp))
		pft->s = set_plus(pft);
	if ((pft->sp == 'c' || pft->sp == 's') && pft->len_mod & _L_L)
		*curr_len = pft->unicode_size;
	else
		*curr_len = ft_strlen(pft->s);
	*show = *curr_len;
}

int		make_s_with_flag(t_pft *pft, long curr_len, long show)
{
	set_prev(pft, &curr_len, &show);
	if (is_num_addr(pft->sp) && ((pft->flags & _FZE) && !(pft->flags & _FMI))
			&& pft->precision < 0)
		show = int_max(pft->width, curr_len);
	else if (is_floating(pft->sp)
			&& ((pft->flags & _FZE) && !(pft->flags & _FMI)))
		show = int_max(pft->width, curr_len);
	else if (pft->sp == 'p' || pft->u_sign)
		show = int_max(curr_len, pft->precision + 2);
	else if (is_num(pft->sp))
		show = int_max(curr_len, (pft->precision +
					(pft->sign < 0 || pft->flags & (_FPL | _FSP))));
	else if ((pft->flags & _FZE) && !(pft->flags & _FMI))
		show = int_max(pft->width, curr_len);
	else if ((pft->sp == 'c' || pft->sp == 's') && pft->len_mod & _L_L)
		show = pft->unicode_size;
	else if (pft->sp == 'c' || pft->sp == '%')
		show = 1;
	else
		(pft->precision >= 0) && (show = int_min(curr_len, pft->precision));
	pft->width = int_max(pft->width, show);
	pft->nchar = pft->width;
	put_out_str(show, curr_len, pft);
	return (1);
}

int		specifier(char *fmt, t_pft *pft, va_list ap)
{
	pft->sp = *fmt;
	if (pft->sp == '%')
		set_percent(pft);
	else if (pft->sp == 'c')
		set_char(pft, ap);
	else if (pft->sp == 's')
		set_string(pft, ap);
	else if (pft->sp == 'p')
		set_point(pft, ap);
	else if (pft->sp == 'i' || pft->sp == 'd')
		set_signed(pft, ap);
	else if (pft->sp == 'u' || pft->sp == 'o'
			|| pft->sp == 'x' || pft->sp == 'X')
		set_unsigned(fmt, pft, ap);
	else if (pft->sp == 'n')
		return (set_length(pft, ap));
	else if (pft->sp == 'f' || pft->sp == 'g' || pft->sp == 'e')
		set_float(pft, ap);
	else
		return (0);
	if (!pft->s)
		pft->s = ft_strdup("(null)");
	return (make_s_with_flag(pft, 0, 0));
}
