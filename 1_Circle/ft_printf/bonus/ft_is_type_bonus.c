/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_type_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/19 12:19:05 by jjeon             #+#    #+#             */
/*   Updated: 2021/06/14 08:37:25 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf_bonus.h"

int	is_num(char c)
{
	return (c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == 'f'
		|| c == 'e'
		|| c == 'g'
		|| c == 'o');
}

int	is_num_addr(char c)
{
	return (c == 'd'
		|| c == 'i'
		|| c == 'u'
		|| c == 'x'
		|| c == 'X'
		|| c == 'p'
		|| c == 'f'
		|| c == 'e'
		|| c == 'g'
		|| c == 'o');
}

int	is_floating(char c)
{
	return (c == 'f'
		|| c == 'g'
		|| c == 'e');
}

int	is_spec(char c)
{
	return (c == 'd'
		|| c == 'i'
		|| c == 'o'
		|| c == 'u'
		|| c == 'x' || c == 'X'
		|| c == 'e' || c == 'E'
		|| c == 'f' || c == 'F'
		|| c == 'g' || c == 'G'
		|| c == 'a' || c == 'A'
		|| c == 'c' || c == 'C'
		|| c == 's' || c == 'S'
		|| c == 'p'
		|| c == 'n'
		|| c == 'm'
		|| c == '%');
}
