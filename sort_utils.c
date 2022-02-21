/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 17:17:07 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/24 19:23:10 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	max_int(t_stack *stacks)
{
	int	i;
	int	max;

	i = stacks->start_b;
	max = stacks->arr_args[i];
	while (i < stacks->end_b + 1)
	{
		if (max < stacks->arr_args[i])
			max = stacks->arr_args[i];
		i++;
	}
	return (max);
}

int	rb_or_rrb(t_stack *stacks)
{
	int	i;
	int	j;
	int	step_i;
	int	step_j;
	int	max;

	step_i = stacks->end_b - stacks->start_b;
	step_j = stacks->end_b - stacks->start_b;
	i = stacks->start_b;
	j = stacks->end_b;
	max = max_int(stacks);
	while (stacks->arr_args[i] != max)
	{
		step_i--;
		i++;
	}
	while (stacks->arr_args[j] != max)
	{
		step_j--;
		j--;
	}
	if (step_i < step_j)
		return (1);
	return (0);
}

int	size_b(t_stack *stacks)
{
	int	size_b;

	if (stacks->end_b == -1)
	{
		size_b = 0;
		return (size_b);
	}
	size_b = stacks->end_b - stacks->start_b;
	return (size_b);
}
