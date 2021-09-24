/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unicode_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 06:38:53 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:38:22 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int				ft_wbyte(unsigned int n)
{
	int	i;

	if (n <= 255)
		return (1);
	i = 0;
	if (n >= FC5)
		i++;
	if (n >= FC4)
		i++;
	if (n >= FC3)
		i++;
	if (n >= FC2)
		i++;
	if (n >= FC1)
		i++;
	i++;
	return (i);
}

int				unicode_top_index(int size, unsigned int n)
{
	if (size == 1)
		return (n);
	else if (size == 2)
		return (0b11000000 + n);
	else if (size == 3)
		return (0b11100000 + n);
	else if (size == 4)
		return (0b11110000 + n);
	else if (size == 5)
		return (0b11111000 + n);
	else if (size == 6)
		return (0b11111100 + n);
	else
		return (0);
}

char			*ft_chrdup(t_pft *pft, unsigned int n)
{
	char	*chr;
	int		size;
	int		i;

	size = ft_wbyte(n);
	if (!(chr = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	chr[i] = '\0';
	while (--i)
	{
		chr[i] = (X8 + n % X7);
		n /= X7;
	}
	chr[0] = unicode_top_index(size, n);
	pft->unicode_size += size;
	return (chr);
}

char			*ft_uni_strdup(t_pft *pft, unsigned int *s)
{
	char	*rst;
	char	*temp;
	char	*next;
	int		i;

	if (!s)
		return (NULL);
	i = 0;
	rst = malloc(0);
	while (s[i])
	{
		next = ft_chrdup(pft, s[i]);
		temp = ft_strjoin(rst, next);
		free(next);
		free(rst);
		rst = temp;
		i++;
	}
	pft->unicode_size = ft_strlen(rst);
	return (rst);
}
