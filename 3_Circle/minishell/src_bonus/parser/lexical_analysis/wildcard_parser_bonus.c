/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_parser_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gjeon <gjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/12 09:30:31 by jjeon             #+#    #+#             */
/*   Updated: 2022/02/14 02:47:50 by gjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	**set_lookup_arr(char pattern[], int n, int m)
{
	int	**lookup;
	int	i;
	int	j;

	lookup = malloc(sizeof(int *) * (n + 1));
	i = -1;
	while (++i <= n)
	{
		lookup[i] = malloc(sizeof(int) * (m + 1));
		ft_memset(lookup[i], 0, sizeof(int) * (m + 1));
	}
	lookup[0][0] = 1;
	j = 0;
	while (++j <= m)
		if (pattern[j - 1] == '*')
			lookup[0][j] = lookup[0][j - 1];
	return (lookup);
}

static int	free_lookup_arr(int **lookup, int n, int m)
{
	int	i;
	int	result;

	i = -1;
	result = lookup[n][m];
	while (++i <= n)
		free(lookup[i]);
	free(lookup);
	return (result);
}

int	pattern_match(char str[], char pattern[], char *wilds)
{
	int	**lookup;
	int	i;
	int	j;

	if (ft_strlen(pattern) == 0)
		return (ft_strlen(str) == 0);
	lookup = set_lookup_arr(pattern, ft_strlen(str), ft_strlen(pattern));
	i = 0;
	while (++i <= (int)ft_strlen(str))
	{
		j = 0;
		while (++j <= (int)ft_strlen(pattern))
		{
			if (pattern[j - 1] == '*' && wilds[j - 1])
				lookup[i][j] = lookup[i][j - 1] || lookup[i - 1][j];
			else if (str[i - 1] == pattern[j - 1])
				lookup[i][j] = lookup[i - 1][j - 1];
			else
				lookup[i][j] = 0;
		}
	}
	return (free_lookup_arr(lookup, ft_strlen(str), ft_strlen(pattern)));
}

static void	add_sort_args(t_list **result, t_token	*token, char *filename)
{
	t_list	*curr;
	t_list	*prev;

	curr = *result;
	prev = NULL;
	while (curr && ft_strncmp(filename, \
		((t_token *)curr->content)->value, ft_strlen(filename)) > 0)
	{
		prev = curr;
		curr = curr->next;
	}
	if (prev == NULL)
	{
		prev = add_list(curr, token);
		if (!prev)
			return ;
		*result = prev;
	}
	else
	{
		prev->next = add_list(curr, token);
		if (!prev->next)
			return ;
	}
}

void	set_args(t_list **result, char *filename)
{
	t_token	*token;

	token = malloc(sizeof(t_token));
	if (!token)
		return ;
	token->is_last = FALSE;
	token->cmd_last = FALSE;
	token->brace_level = 0;
	token->value = ft_strdup(filename);
	token->type = COMMAND;
	if (!(*result))
	{
		*result = malloc(sizeof(t_list));
		if (!(*result))
		{
			free(token->value);
			free(token);
			return ;
		}
		(*result)->content = token;
		(*result)->next = NULL;
	}
	else
		add_sort_args(result, token, filename);
}
