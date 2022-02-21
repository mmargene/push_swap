/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:34:40 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/24 19:06:03 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_split(t_stack *stacks, char *argv)
{
	char	**tmp_split;
	int		j;

	j = 0;
	tmp_split = ft_split(argv, ' ');
	if (!tmp_split)
		ft_error(stacks);
	while (tmp_split[j])
	{
		stacks->arr_args[stacks->number++] = ft_atoi_ps(tmp_split[j], stacks);
		free(tmp_split[j]);
		j++;
	}
	free(tmp_split);
	return (0);
}

int	ft_check_repeat(t_stack *stacks)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < stacks->number)
	{
		while (j < stacks->number)
		{
			if (stacks->arr_args[i] == stacks->arr_args[j] && (j != i))
				return (1);
			j++;
		}
		i++;
		j = 0;
	}
	return (0);
}

int	ft_check_sort(t_stack *stacks)
{
	int	i;

	i = 0;
	if (stacks->arr_args[i] < stacks->arr_args[i + 1])
	{
		while (stacks->arr_args[i] < stacks->arr_args[i + 1])
		{
			i++;
			if (i == (stacks->number) - 1)
				return (1);
		}
	}
	return (0);
}

int	ft_check(t_stack *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 0)
	{
		while (argc != 1)
		{
			if (!ft_strchr(argv[i], ' ') && ft_strlen(argv[i]) > 0)
				stacks->arr_args[stacks->number++] = \
				ft_atoi_ps(argv[i], stacks);
			else if (ft_strchr(argv[i], ' '))
				ft_check_split(stacks, argv[i]);
			else if (ft_strlen(argv[i]) < 1)
				ft_error(stacks);
			i++;
			argc--;
		}
	}
	if (ft_check_repeat(stacks))
		ft_error(stacks);
	return (0);
}
