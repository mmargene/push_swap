/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/16 13:05:46 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/24 19:22:51 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_2(t_stack *stacks)
{
	if (stacks->arr_args[0] > \
	stacks->arr_args[1])
		sa(stacks, 1);
	else
		ft_error(stacks);
}

void	ft_sort(t_stack *stacks)
{
	if (stacks->number == 2)
		ft_sort_2(stacks);
	else if (stacks->number == 3)
		ft_sort_3(stacks);
	else if (stacks->number == 4)
		ft_sort_5(stacks, 4);
	else if (stacks->number < 6)
		ft_sort_5(stacks, 5);
	else if (stacks->number < 101)
		ft_sort_100(stacks);
	else
		ft_sort_500(stacks);
}
