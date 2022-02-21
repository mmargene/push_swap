/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:33:25 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/20 18:20:53 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_5_4(t_stack *stacks)
{
	if (stacks->arr_args[stacks->start_b] > \
	stacks->arr_args[stacks->start_a + 2] && \
	stacks->arr_args[stacks->start_b] < \
	stacks->arr_args[stacks->start_a + 3] && \
	stacks->arr_args[stacks->start_a + 3] == \
	stacks->arr_args[stacks->end_a])
	{
		rra(stacks, 1);
		pa(stacks, 1);
		ra(stacks, 1);
		ra(stacks, 1);
	}
}

void	ft_sort_5_3(t_stack *stacks)
{
	if (stacks->arr_args[stacks->start_b] > \
	stacks->arr_args[stacks->start_a + 1] && \
	stacks->arr_args[stacks->start_b] < \
	stacks->arr_args[stacks->start_a + 2] && \
	stacks->arr_args[stacks->start_a + 2] != \
	stacks->arr_args[stacks->end_a])
	{
		ra(stacks, 1);
		pa(stacks, 1);
		sa(stacks, 1);
		rra(stacks, 1);
	}
}

void	ft_sort_5_2(t_stack *stacks)
{
	if (stacks->arr_args[stacks->start_b] > \
	stacks->arr_args[stacks->start_a + 1] && \
	stacks->arr_args[stacks->start_b] < \
	stacks->arr_args[stacks->start_a + 2] && \
	stacks->arr_args[stacks->start_a + 2] == \
	stacks->arr_args[stacks->end_a])
	{
		rra(stacks, 1);
		pa(stacks, 1);
		ra(stacks, 1);
		ra(stacks, 1);
	}
}

void	ft_sort_5_1(t_stack *stacks)
{
	if (stacks->arr_args[stacks->start_b] < \
	stacks->arr_args[stacks->start_a])
		pa(stacks, 1);
	if (stacks->arr_args[stacks->start_b] > \
	stacks->arr_args[stacks->end_a])
	{
		pa(stacks, 1);
		ra(stacks, 1);
	}
	if (stacks->arr_args[stacks->start_b] > \
	stacks->arr_args[stacks->start_a] && \
	stacks->arr_args[stacks->start_b] < \
	stacks->arr_args[stacks->start_a + 1])
	{
		ra(stacks, 1);
		pa(stacks, 1);
		rra(stacks, 1);
	}
}

void	ft_sort_5(t_stack *stacks, int number)
{
	pb(stacks, 1);
	if (number == 5)
		pb(stacks, 1);
	ft_sort_3(stacks);
	while (stacks->end_b != -1)
	{
		ft_sort_5_1(stacks);
		ft_sort_5_2(stacks);
		ft_sort_5_3(stacks);
		ft_sort_5_4(stacks);
	}
}
