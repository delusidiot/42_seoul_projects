/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_itoa_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/25 15:52:56 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:38:02 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int			s_num_len(unsigned long long n, int is_signed, int numeral)
{
	int	len;

	len = 0;
	if (n == 0)
		len++;
	if (is_signed && (long long)n < 0)
	{
		len++;
		n = -n;
	}
	while (n != 0)
	{
		n /= numeral;
		len++;
	}
	return (len);
}

char		*ft_signed_itoa(unsigned long long n,
			int is_signed, int numeral)
{
	int		len;
	int		sign;
	int		digit;
	char	*rst;

	len = s_num_len(n, is_signed, numeral);
	sign = 1;
	if (is_signed && (long long)n < 0)
		sign = -1;
	if (!(rst = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	rst[len] = 0;
	n *= sign;
	while (--len >= 0)
	{
		digit = n % numeral;
		rst[len] = "0123456789abcdef"[digit];
		n /= numeral;
	}
	if (is_signed && sign < 0)
		rst[0] = '-';
	return (rst);
}
