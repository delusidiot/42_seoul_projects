/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 17:59:20 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/01 14:29:25 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	isminus(int n)
{
	if (n < 0)
		return (-n);
	else
		return (n);
}

int	num_len(int n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n != 0)
	{
		n /= 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	int		len;
	int		sign;
	int		digit;
	char	*rst;

	len = num_len(n);
	sign = n;
	rst = (char *)malloc(sizeof(char) * (len + 1));
	if (!rst)
		return (NULL);
	rst[len] = 0;
	len--;
	while (len >= 0)
	{
		digit = isminus(n % 10);
		rst[len] = digit + '0';
		n /= 10;
		len--;
	}
	if (sign < 0)
		rst[0] = '-';
	return (rst);
}
