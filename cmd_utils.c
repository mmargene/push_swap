/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:25:39 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/20 18:11:40 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_stacks(t_stack *stacks)
{
	stacks->start_a = 0;
	stacks->end_a = stacks->number - 1;
	stacks->start_b = stacks->length / 2;
	stacks->end_b = -1;
}

void	shift_right(t_stack *stacks, int a_b)
{
	int	size_a;
	int	size_b;

	size_a = stacks->end_a;
	size_b = stacks->end_b;
	if (a_b == 1)
	{
		while (stacks->start_a < size_a)
		{
			stacks->arr_args[size_a] = stacks->arr_args[size_a - 1];
			size_a--;
		}
	}
	else
	{
		while (stacks->start_b < size_b)
		{
			stacks->arr_args[size_b] = stacks->arr_args[size_b - 1];
			size_b--;
		}
	}
}

void	shift_left(t_stack *stacks, int a_b)
{
	int	size_a;
	int	size_b;

	size_a = stacks->start_a + 1;
	size_b = stacks->start_b + 1;
	if (a_b == 1)
	{
		while (stacks->end_a + 1 > size_a)
		{
			stacks->arr_args[size_a - 1] = stacks->arr_args[size_a];
			size_a++;
		}
		stacks->arr_args[size_a - 1] = 0;
	}
	else
	{
		while (stacks->end_b + 1 > size_b)
		{
			stacks->arr_args[size_b - 1] = stacks->arr_args[size_b];
			size_b++;
		}
		stacks->arr_args[size_b - 1] = 0;
	}
}

int	check_end(t_stack *stacks, int a_b)
{
	if (a_b == 1 && stacks->end_a == -1)
		return (1);
	if (a_b == 2 && stacks->end_b == -1)
		return (1);
	return (0);
}

int	check_one(t_stack *stacks, int a_b)
{
	if (a_b == 1 && (stacks->end_a - \
	stacks->start_a) == 0)
		return (1);
	if (a_b == 2 && (stacks->end_b - \
	stacks->start_b) == 0)
		return (1);
	return (0);
}
