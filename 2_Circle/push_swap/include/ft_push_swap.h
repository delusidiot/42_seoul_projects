/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjeon <jjeon@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 09:33:09 by jjeon             #+#    #+#             */
/*   Updated: 2021/07/23 02:18:16 by jjeon            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <unistd.h>
# include <stdlib.h>
# include "libft.h"
# include "get_next_line.h"
# include <stdio.h>

# define TRUE		1
# define FALSE		0

typedef struct s_push
{
	int					*a_stack;
	int					a_top;
	int					*b_stack;
	int					b_top;
	int					*sorted_stack;
	int					len;
	struct s_command	*command_list;
	struct s_command	*last_command;
}	t_push;

typedef struct s_command
{
	char				*c;
	struct s_command	*next;
}	t_command;

/*
** operations
*/

void	ft_swap(t_push *p, char c);
void	ft_push(t_push *p, char c);
void	ft_rotate(t_push *p, char c);
void	ft_reverse_rotate(t_push *p, char c);
void	push_command(t_push *p, char *s, char c);
void	print_command(t_push *p);
int		is_next_smaller(t_push *p, int pivot);
int		is_next_bigger(t_push *p, int pivot);

void	push_init(t_push *p);
void	push_free(t_push *p);
void	free_command(t_command *comm);
void	create_first_command(t_push *p);
int		push_args(int argc, char **argv, t_push *p);
int		word_counter(char const *s, char c);
int		is_number(char *s);
long	ft_atol(char *num);
int		ft_strcmp(char *s1, char *s2);
void	argument_to_order(t_push *p);
void	sorted_stack_free(t_push *p);
void	print_string(char *s);

void	ft_quick_sort(int arr[], int low, int high);
int		is_sorted(t_push *p);
int		first_divide_stack(t_push *p);
void	sort_stack(t_push *p);
void	print_command_string(char *s, char c);

/*
** stack check
*/
int		search_index(t_push *p, int num, char st);
int		is_from_to(t_push *p, int from, int to);

void	stack_sort(t_push *p);
void	first_divide(t_push *p, int pivot);
int		move_b_stack(t_push *p, int idx, char c, int is);
void	from_to_push(t_push *p, int from, int to);

/*
** huge stack sort
*/

void	counting_init(int *a, int *b, int *p);
int		get_stack_max(int *stack, int top, int end);
int		get_stack_min(int *stack, int top, int end);
int		get_pivot_s(int *stack, int top, int end);
int		get_pivot_b(int *stack, int top, int end);
void	rest_a_stack(t_push *p, int end);
void	rest_b_stack(t_push *p, int end);
void	reverse_rotate_A_B(t_push *p, int ra, int rb);
void	huge_stack_sort(t_push *p);
void	A_to_B(t_push *p, int end);
void	B_to_A(t_push *p, int end);
#endif
