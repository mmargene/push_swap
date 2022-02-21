/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 02:40:01 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/24 19:08:06 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	static t_stack	stacks;

	ft_check_length(&stacks, argc, argv);
	stacks.length *= 2;
	stacks.arr_args = ft_calloc(stacks.length, 4);
	if (stacks.arr_args == NULL)
		exit(ERROR_CODE);
	if (argc == 1)
		return (0);
	ft_check(&stacks, argc, argv);
	init_stacks(&stacks);
	if (!get_cmd(&stacks))
		ft_error(&stacks);
	if (ft_check_sort(&stacks) && check_end(&stacks, 2))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free(stacks.arr_args);
	return (0);
}
