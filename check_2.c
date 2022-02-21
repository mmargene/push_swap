/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:44:36 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/18 02:54:33 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_split_length(t_stack *stacks, char *argv)
{
	char	**tmp_split;
	int		j;

	j = 0;
	tmp_split = ft_split(argv, ' ');
	if (!tmp_split)
		ft_error(stacks);
	while (tmp_split[j])
	{
		ft_atoi_ps(tmp_split[j], stacks);
		stacks->length++;
		free(tmp_split[j]);
		j++;
	}
	free(tmp_split);
	return (0);
}

void	ft_check_length(t_stack *stacks, int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc > 0)
	{
		while (argc != 1)
		{
			if (!ft_strchr(argv[i], ' '))
			{
				ft_atoi_ps(argv[i], stacks);
				stacks->length++;
			}	
			if (ft_strchr(argv[i], ' '))
				ft_check_split_length(stacks, argv[i]);
			i++;
			argc--;
		}
	}
}
