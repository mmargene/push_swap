/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 03:36:02 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/20 18:12:04 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ra(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 1))
		return (1);
	tmp = stacks->arr_args[stacks->start_a];
	shift_left(stacks, 1);
	stacks->arr_args[stacks->end_a] = tmp;
	if (f == 1)
		write(1, "ra\n", 3);
	return (1);
}

int	rb(t_stack *stacks, int f)
{
	int	tmp;

	if (check_end(stacks, 2))
		return (1);
	tmp = stacks->arr_args[stacks->start_b];
	shift_left(stacks, 2);
	stacks->arr_args[stacks->end_b] = tmp;
	if (f == 1)
		write(1, "rb\n", 3);
	return (1);
}

int	rr(t_stack *stacks, int f)
{
	ra(stacks, 2);
	rb(stacks, 2);
	if (f == 1)
		write(1, "rr\n", 3);
	return (1);
}
