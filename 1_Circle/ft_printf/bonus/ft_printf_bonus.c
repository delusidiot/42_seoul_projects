/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 19:53:31 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:37:39 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int			ft_printf(const char *format, ...)
{
	int		done;
	va_list	ap;

	va_start(ap, format);
	done = printf_format(format, ap);
	va_end(ap);
	return (done);
}
