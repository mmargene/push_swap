/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:44:15 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/24 19:52:32 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "gnl/get_next_line.h"

# define ERROR_CODE -1

typedef struct s_stack
{
	int				number;
	int				length;
	int				start_a;
	int				end_a;
	int				start_b;
	int				end_b;
	int				error;
	int				*arr_args;
}				t_stack;

// utils.c
int		ft_check_number(char *str, t_stack *stacks);
int		ft_atoi_ps(char *str, t_stack *stacks);
void	ft_error(t_stack *stacks);

// check_1.c
int		ft_check_split(t_stack *stacks, char *argv);
int		ft_check_repeat(t_stack *stacks);
int		ft_check_sort(t_stack *stacks);
int		ft_check(t_stack *stacks, int argc, char **argv);

// check2.c
void	ft_check_length(t_stack *stacks, int argc, char **argv);
int		ft_check_split_length(t_stack *stacks, char *argv);

// cmd_1.c
int		sa(t_stack *stacks, int f);
int		sb(t_stack *stacks, int f);
int		ss(t_stack *stacks, int f);
int		pa(t_stack *stacks, int f);
int		pb(t_stack *stacks, int f);

// cmd_2.c
int		ra(t_stack *stacks, int f);
int		rb(t_stack *stacks, int f);
int		rr(t_stack *stacks, int f);

// cmd_3.c
int		rra(t_stack *stacks, int f);
int		rrb(t_stack *stacks, int f);
int		rrr(t_stack *stacks, int f);

// cmd_utils.c
void	init_stacks(t_stack *stacks);
void	shift_right(t_stack *stacks, int a_b);
void	shift_left(t_stack *stacks, int a_b);
int		check_end(t_stack *stacks, int a_b);
int		check_one(t_stack *stacks, int a_b);

// sort.c
void	ft_sort(t_stack *stacks);

// sort_3.c
void	ft_sort_3(t_stack *stacks);

// sort_5.c
void	ft_sort_5_4(t_stack *stacks);
void	ft_sort_5_3(t_stack *stacks);
void	ft_sort_5_2(t_stack *stacks);
void	ft_sort_5_1(t_stack *stacks);
void	ft_sort_5(t_stack *stacks, int number);

// sort_100_500.c
void	ft_sort_100(t_stack *stacks);
void	ft_sort_500(t_stack *stacks);
void	ft_sort_pa(t_stack *stacks);

// sort_utils.c
int		max_int(t_stack *stacks);
int		rb_or_rrb(t_stack *stacks);
int		size_b(t_stack *stacks);

// gnl
char	*get_next_line(int fd);

// checker_utils.c
int		ft_strcmp(char *s1, char *s2);
int		check_cmd(char *cmd, t_stack *stacks);
int		get_cmd(t_stack *stacks);

#endif