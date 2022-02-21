/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 05:26:52 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/20 18:12:09 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 1))
		return (1);
	tmp = stacks->arr_args[stacks->end_a];
	shift_right(stacks, 1);
	stacks->arr_args[stacks->start_a] = tmp;
	if (f == 1)
		write(1, "rra\n", 4);
	return (1);
}

int	rrb(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 2))
		return (1);
	tmp = stacks->arr_args[stacks->end_b];
	shift_right(stacks, 2);
	stacks->arr_args[stacks->start_b] = tmp;
	if (f == 1)
		write(1, "rrb\n", 4);
	return (1);
}

int	rrr(t_stack *stacks, int f)
{
	rra(stacks, 2);
	rrb(stacks, 2);
	if (f == 1)
		write(1, "rrr\n", 4);
	return (1);
}
