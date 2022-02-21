/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 16:44:39 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/23 19:58:17 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_stack	stacks;

	if (argc == 1)
		return (1);
	ft_check_length(&stacks, argc, argv);
	stacks.length *= 2;
	stacks.arr_args = ft_calloc(stacks.length, 4);
	if (stacks.arr_args == NULL)
		exit(ERROR_CODE);
	ft_check(&stacks, argc, argv);
	init_stacks(&stacks);
	if (ft_check_sort(&stacks) || stacks.number == 1)
	{
		free(stacks.arr_args);
		return (0);
	}
	ft_sort(&stacks);
	free(stacks.arr_args);
	return (0);
}
