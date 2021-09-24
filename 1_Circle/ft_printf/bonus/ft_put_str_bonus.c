/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_str_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:30:29 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 16:38:15 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

void	put_zero(long show, long curr_len, t_pft *pft)
{
	while (pft->width > show)
	{
		write(1, " ", 1);
		pft->width--;
	}
	if (pft->sp == 'p' || pft->u_sign)
	{
		write(1, pft->s++, 1);
		write(1, pft->s++, 1);
		pft->width -= 2;
		show -= 2;
		curr_len -= 2;
	}
	if (is_num_addr(pft->sp) && (pft->sign < 0 || (pft->flags & (_FPL | _FSP))))
	{
		write(1, pft->s++, 1);
		pft->width--;
		show--;
		curr_len--;
	}
	while (show-- > curr_len)
		write(1, "0", 1);
	while (curr_len--)
		write(1, pft->s++, 1);
}

void	put_out_str(long show, long curr_len, t_pft *pft)
{
	char *temp;

	temp = pft->s;
	if (pft->flags & _FMI)
		put_left(show, curr_len, pft);
	else if (pft->flags & _FZE)
		put_zero(show, curr_len, pft);
	else
		put_right(show, curr_len, pft);
	if (temp)
		free(temp);
}
