/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_left_right_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/20 09:39:42 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:37:47 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_right_num(long *show, long *curr_len, t_pft *pft)
{
	if (pft->sp == 'p' || pft->u_sign)
	{
		write(1, pft->s++, 1);
		write(1, pft->s++, 1);
		pft->width -= 2;
		(*show) -= 2;
		(*curr_len) -= 2;
	}
	if (pft->sign < 0 || (pft->flags & (_FPL | _FSP)))
	{
		write(1, pft->s++, 1);
		pft->width--;
		(*show)--;
		(*curr_len)--;
	}
	while ((*show > *curr_len) && pft->width)
	{
		write(1, "0", 1);
		pft->width--;
		(*show)--;
	}
}

void	put_right(long show, long curr_len, t_pft *pft)
{
	while (pft->width > show)
	{
		write(1, " ", 1);
		pft->width--;
	}
	if (is_num_addr(pft->sp))
		put_right_num(&show, &curr_len, pft);
	write(1, pft->s, show);
}

void	put_left_num(long *show, long *curr_len, t_pft *pft)
{
	if (pft->sp == 'p' || pft->u_sign)
	{
		write(1, pft->s++, 1);
		write(1, pft->s++, 1);
		pft->width -= 2;
		(*show) -= 2;
		(*curr_len) -= 2;
	}
	if (pft->sign < 0 || (pft->flags & (_FPL | _FSP)))
	{
		write(1, pft->s++, 1);
		pft->width--;
		(*show)--;
		(*curr_len)--;
	}
	while (pft->width && (*show > *curr_len))
	{
		write(1, "0", 1);
		pft->width--;
		(*show)--;
	}
	while ((*show)-- && pft->width--)
		write(1, pft->s++, 1);
}

void	put_left(long show, long curr_len, t_pft *pft)
{
	if (!(is_num_addr(pft->sp)))
	{
		write(1, pft->s, show);
		pft->width -= show;
		show = 0;
	}
	else
		put_left_num(&show, &curr_len, pft);
	while (pft->width--)
		write(1, " ", 1);
}
