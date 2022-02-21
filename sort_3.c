/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/17 16:33:21 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/23 17:32:20 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_3(t_stack *stacks)
{
	int	a;
	int	b;
	int	c;

	a = stacks->arr_args[0];
	b = stacks->arr_args[1];
	c = stacks->arr_args[2];
	if (a < b && a < c && b > c)
	{
		rra(stacks, 1);
		sa(stacks, 1);
	}
	if (a < b && a > c && b > c)
		rra(stacks, 1);
	if (a > b && a < c && b < c)
		sa(stacks, 1);
	if (a > b && a > c && b < c)
		ra(stacks, 1);
	if (a > b && a > c && b > c)
	{
		ra(stacks, 1);
		sa(stacks, 1);
	}
}
