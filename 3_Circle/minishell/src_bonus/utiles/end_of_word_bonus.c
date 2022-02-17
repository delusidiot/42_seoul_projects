/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   end_of_word_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 02:39:47 by gjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:39:47 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	end_of_word(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\t' || str[i] == '\n' || \
			str[i] == '\v' || str[i] == '\f' || \
			str[i] == '\r' || str[i] == ' ')
			return (i);
		i++;
	}
	return (i);
}
