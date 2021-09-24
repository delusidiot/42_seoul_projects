/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_convert.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 08:23:32 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/06 21:34:00 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	set_float_to_array(t_pft *pft)
{
	unsigned long long	v;
	unsigned long long	mantissa;
	int					exponent;

	mantissa = 0;
	v = *(unsigned long long*)&pft->u_v.ld;
	if (pft->u_v.ld)
		mantissa = (v & ((1ULL << 52) - 1)) + (1ULL << 52);
	v >>= 52;
	exponent = v & ((1 << 11) - 1);
	exponent -= 1023;
	v >>= 11;
	if (v)
		pft->sign = -1;
	if (exponent == 1024)
		set_floting_type(mantissa, pft);
	set_floating_integer(mantissa, exponent, pft);
	set_floating_decimal(mantissa, exponent, pft);
}

char	*set_float_integer(t_pft *pft)
{
	char	*pre;
	char	*minus;
	char	*tmp;
	int		i;
	int		j;

	i = 800;
	while (!pft->f_integer[i] && i)
		i--;
	if (!(pre = malloc(sizeof(char) * (i + 2))))
		return (NULL);
	j = i + 1;
	while (--j >= 0)
		pre[i - j] = (pft->f_integer[j] + '0');
	pre[i + 1] = '\0';
	if (pft->sign < 0)
	{
		minus = ft_chrdup(pft, '-');
		tmp = pre;
		pre = ft_strjoin(minus, pre);
		free(minus);
		free(tmp);
	}
	return (pre);
}

void	set_float_str(t_pft *pft, char sp)
{
	char	*prev;
	char	*saf;

	if (sp == 'g' && !(pft->flags & _FSH))
		saf = set_gsp_decimal(pft);
	else if (sp == 'g' && (pft->flags & _FSH))
		saf = set_gsp_sh_decimal(pft);
	else
		saf = set_fsp_decimal(pft);
	prev = set_float_integer(pft);
	pft->s = ft_strjoin(prev, saf);
	pft->nchar = ft_strlen(pft->s);
	free(prev);
	free(saf);
}

int		set_float(t_pft *pft, va_list ap)
{
	char sp;

	sp = pft->sp;
	pft->u_v.ld = va_arg(ap, double);
	pft->precision = int_min(F_DEC_S, pft->precision);
	if (pft->precision < 0)
		pft->precision = 6;
	if (pft->sp == 'g' && pft->precision == 0)
		pft->precision = 1;
	set_float_to_array(pft);
	if (pft->f_type)
		return (is_float_type(pft));
	if (pft->sp == 'g')
		check_gsp(pft);
	if (pft->sp == 'e')
		check_esp(pft);
	set_round(pft);
	if (pft->sp == 'e' || (sp == 'g'
		&& pft->sdig == 1 && pft->precision == 0))
		set_exponent_tail(pft, sp);
	set_float_str(pft, sp);
	return (1);
}
