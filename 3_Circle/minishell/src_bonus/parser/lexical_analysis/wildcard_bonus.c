/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:33 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 11:57:03 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static t_list	*get_whidcard_list(char *wild, char *wilds, DIR *dir_ptr)
{
	struct dirent	*file_info;
	t_list			*result;

	if (!wilds)
		return (NULL);
	result = NULL;
	while (TRUE)
	{
		file_info = readdir(dir_ptr);
		if (!file_info)
			break ;
		if (ft_strncmp(file_info->d_name, ".", 1) || *wild == '.')
		{
			if (pattern_match(file_info->d_name, wild, wilds))
				set_args(&result, file_info->d_name);
		}
	}
	return (result);
}

static t_list	*set_result_list(t_list	*result, t_token *token)
{
	if (!result)
	{
		result = malloc(sizeof(t_list));
		if (!result)
		{
			free(token->value);
			free(token);
			return (NULL);
		}
		result->content = token;
		result->next = NULL;
	}
	else
	{
		free(token->value);
		free(token);
	}
	return (result);
}

t_list	*get_wildcard_files(t_token *token, char *wilds, t_user *user)
{
	DIR		*dir_ptr;
	t_list	*result;

	result = NULL;
	dir_ptr = opendir(user->pwd);
	if (!dir_ptr)
	{
		free(token->value);
		free(token);
		return (NULL);
	}
	result = get_whidcard_list(token->value, wilds, dir_ptr);
	closedir(dir_ptr);
	free(wilds);
	return (set_result_list(result, token));
}

t_list	*add_list(t_list *curr, t_token *token)
{
	t_list	*lst;

	lst = malloc(sizeof(t_list));
	if (!lst)
	{
		free(token->value);
		free(token);
		return (NULL);
	}
	lst->content = token;
	lst->next = curr;
	return (lst);
}
