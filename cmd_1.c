/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 09:54:44 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/20 18:11:55 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 1) || check_one(stacks, 1))
		return (1);
	tmp = stacks->arr_args[0];
	stacks->arr_args[0] = stacks->arr_args[1];
	stacks->arr_args[1] = tmp;
	if (f == 1)
		write(1, "sa\n", 3);
	return (1);
}

int	sb(t_stack *stacks, int f)
{
	int	tmp;
	int	i;
	int	j;

	if (check_end(stacks, 2) || check_one(stacks, 2))
		return (1);
	i = stacks->start_b;
	j = stacks->start_b + 1;
	tmp = stacks->arr_args[i];
	stacks->arr_args[i] = stacks->arr_args[j];
	stacks->arr_args[j] = tmp;
	if (f == 1)
		write(1, "sb\n", 3);
	return (1);
}

int	ss(t_stack *stacks, int f)
{
	sa(stacks, 2);
	sb(stacks, 2);
	if (f == 1)
		write(1, "ss\n", 3);
	return (1);
}

int	pa(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 2))
		return (1);
	tmp = stacks->arr_args[stacks->start_b];
	if (stacks->end_a == -1)
		stacks->end_a = stacks->start_a;
	else
		stacks->end_a++;
	shift_right(stacks, 1);
	shift_left(stacks, 2);
	stacks->end_b--;
	if (stacks->end_b == (stacks->start_b - 1))
		stacks->end_b = -1;
	stacks->arr_args[stacks->start_a] = tmp;
	if (f == 1)
		write(1, "pa\n", 3);
	return (1);
}

int	pb(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 1))
		return (1);
	tmp = stacks->arr_args[0];
	if (stacks->end_b == -1)
		stacks->end_b = stacks->start_b;
	else
		stacks->end_b++;
	shift_left(stacks, 1);
	shift_right(stacks, 2);
	stacks->end_a--;
	if (stacks->end_a == (stacks->start_a - 1))
		stacks->end_a = -1;
	stacks->arr_args[stacks->start_b] = tmp;
	if (f == 1)
		write(1, "pb\n", 3);
	return (1);
}
