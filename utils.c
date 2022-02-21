/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 08:29:51 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/23 17:36:35 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_check_number(char *str, t_stack *stacks)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isalpha(str[i]))
			ft_error(stacks);
		if (str[i] == '-' || str[i] == '+')
		{
			i++;
			if (str[i] == '-' || str[i] == '+')
				ft_error(stacks);
		}
		i++;
	}
	return (1);
}

int	ft_atoi_ps(char *str, t_stack *stacks)
{
	size_t	n;
	int		negative;
	int		i;

	i = 0;
	n = 0;
	negative = 1;
	ft_check_number(str, stacks);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative = -1;
	while ((str[i]) && (ft_isdigit(str[i])))
	{
		n = 10 * n + (str[i] - 48);
		if ((negative == -1) && (n > 2147483648))
			ft_error(stacks);
		if ((negative == 1) && (n > 2147483647))
			ft_error(stacks);
		i++;
	}
	return ((int)n * negative);
}

void	ft_error(t_stack *stacks)
{
	free(stacks->arr_args);
	write(1, "Error\n", 6);
	exit(ERROR_CODE);
}
