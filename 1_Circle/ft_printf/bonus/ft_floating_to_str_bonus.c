/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_floating_to_str_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 14:29:01 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:37:03 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

char	*set_esp_decimal2(t_pft *pft)
{
	char	*exponent;
	int		i;

	exponent = malloc(sizeof(char) * 4);
	if (pft->exponent < 0)
		exponent[0] = '-';
	else
		exponent[0] = '+';
	exponent[1] = '0';
	i = int_abs(pft->exponent);
	exponent[2] = i + '0';
	exponent[3] = '\0';
	return (exponent);
}

char	*set_esp_decimal(char *saf, t_pft *pft)
{
	char	*e;
	char	*exnum;
	char	*tmp;
	char	*tmp2;

	e = ft_strdup("e");
	if (pft->exponent < -9)
		exnum = ft_itoa(pft->exponent);
	else if (pft->exponent > 9)
	{
		tmp = ft_strdup("+");
		tmp2 = ft_itoa(pft->exponent);
		exnum = ft_strjoin(tmp, tmp2);
		free(tmp);
		free(tmp2);
	}
	else
		exnum = set_esp_decimal2(pft);
	tmp = ft_strjoin(e, exnum);
	free(e);
	free(exnum);
	tmp2 = ft_strjoin(saf, tmp);
	free(saf);
	free(tmp);
	return (tmp2);
}

char	*set_gsp_sh_decimal(t_pft *pft)
{
	char	*saf;
	int		i;
	int		j;

	i = pft->precision;
	if (i < 2)
	{
		saf = ft_strdup(".");
		pft->precision = 0;
		i = 0;
	}
	else
	{
		saf = malloc(sizeof(char) * (i + 2));
		saf[0] = '.';
		saf[i + 1] = '\0';
	}
	j = -1;
	while (++j < i)
		saf[j + 1] = pft->f_decimal[F_DEC_S - 1 - j] + '0';
	if (pft->sp == 'e')
		saf = set_esp_decimal(saf, pft);
	return (saf);
}

char	*set_gsp_decimal(t_pft *pft)
{
	char	*saf;
	int		i;
	int		j;

	while (pft->precision && !pft->f_decimal[F_DEC_S - pft->precision])
		pft->precision--;
	i = pft->precision;
	if (i == 0)
		saf = ft_strdup("");
	else
	{
		saf = malloc(sizeof(char) * (i + 2));
		saf[0] = '.';
		saf[i + 1] = '\0';
	}
	j = -1;
	while (++j < i)
		saf[j + 1] = pft->f_decimal[F_DEC_S - 1 - j] + '0';
	if (pft->sp == 'e')
		saf = set_esp_decimal(saf, pft);
	return (saf);
}

char	*set_fsp_decimal(t_pft *pft)
{
	char	*saf;
	int		i;
	int		j;

	i = pft->precision;
	if (i == 0 && !(pft->flags & _FSH))
		saf = ft_strdup("");
	else
	{
		saf = malloc(sizeof(char) * (i + 2));
		saf[0] = '.';
		saf[i + 1] = '\0';
	}
	j = -1;
	while (++j < i)
		saf[j + 1] = pft->f_decimal[F_DEC_S - 1 - j] + '0';
	j = 0;
	if (pft->sp == 'e')
		saf = set_esp_decimal(saf, pft);
	return (saf);
}
