/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_100_500.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 17:16:07 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/20 18:49:34 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_100(t_stack *stacks)
{
	int	l;

	l = 0;
	while (stacks->end_a != -1)
	{
		if (l > 1 && stacks->arr_args[0] <= l)
		{
			pb(stacks, 1);
			l++;
			rb(stacks, 1);
		}
		else if (stacks->arr_args[0] <= l + 15)
		{
			pb(stacks, 1);
			l++;
		}
		else if (stacks->arr_args[0] >= l)
			ra(stacks, 1);
	}
	ft_sort_pa(stacks);
}

void	ft_sort_500(t_stack *stacks)
{
	int	l;

	l = 0;
	while (stacks->end_a != -1)
	{
		if (l > 1 && stacks->arr_args[0] <= l)
		{
			pb(stacks, 1);
			l++;
			rb(stacks, 1);
		}
		else if (stacks->arr_args[0] <= l + 30)
		{
			pb(stacks, 1);
			l++;
		}
		else if (stacks->arr_args[0] >= l)
			ra(stacks, 1);
	}
	ft_sort_pa(stacks);
}

void	ft_sort_pa(t_stack *stacks)
{
	while (stacks->end_b != -1)
	{
		if (stacks->arr_args[stacks->start_b] == max_int(stacks))
			pa(stacks, 1);
		else if (stacks->arr_args[stacks->start_b] != \
		max_int(stacks) && rb_or_rrb(stacks))
			rrb(stacks, 1);
		else if (stacks->arr_args[stacks->start_b] != \
		max_int(stacks) && !rb_or_rrb(stacks))
			rb(stacks, 1);
	}
}
