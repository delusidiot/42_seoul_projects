/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 05:05:18 by jjeon             #+#    #+#             */
/*   Updated: 2021/10/23 05:05:19 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int is_hex(char *hex)
{
	int i;
	int j;
	int check;
	char *digits;

	if (ft_strlen(hex) > 2 && hex[0] =='0' && (hex[1] =='x' || hex[1] == 'X'))
	{
		i = 1;
		digits = "0123456789abcdefABCDEF";
		while (hex[++i]){
			j = -1;
			check = FALSE;
			while (digits[++j]){
				if (hex[i] == digits[j])
					check = TRUE;
			}
			if (!check)
				return (FALSE);
		}
	}
	else
		return (FALSE);
	return (TRUE);
}

int is_number(char *num)
{
	int i;

	i = -1;
	if (num[0] == '-')
		i++;
	while (num[++i])
		if (!ft_isdigit(num[i]))
			return (FALSE);
	return (TRUE);
}

int hex_to_int(char *hex)
{
	char *digits;
	int num;
	int i;
	int j;

	i = 1;
	num = 0;
	while (hex[++i]){
		digits = "0123456789ABCDEF";
		if (hex[i]>='a' && hex[i] <= 'z')
			digits = "0123456789abcdef";
		j = 0;
		while (hex[i] != digits[j])
			j++;
		num *= 16;
		num += j;
	}
	return (num);
}
