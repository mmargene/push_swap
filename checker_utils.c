/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 20:38:41 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/18 01:54:46 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (!res && *s1 && *s2)
		res = *(s1++) - *(s2++);
	if (res || (!*s1 && !*s2))
		return (res);
	res = *s1 - *s2;
	return (res);
}

int	check_cmd(char *cmd, t_stack *stacks)
{
	if (!ft_strcmp(cmd, "sa\n"))
		return (sa(stacks, 2));
	else if (!ft_strcmp(cmd, "sb\n"))
		return (sb(stacks, 2));
	else if (!ft_strcmp(cmd, "ss\n"))
		return (ss(stacks, 2));
	else if (!ft_strcmp(cmd, "pa\n"))
		return (pa(stacks, 2));
	else if (!ft_strcmp(cmd, "pb\n"))
		return (pb(stacks, 2));
	else if (!ft_strcmp(cmd, "ra\n"))
		return (ra(stacks, 2));
	else if (!ft_strcmp(cmd, "rb\n"))
		return (rb(stacks, 2));
	else if (!ft_strcmp(cmd, "rr\n"))
		return (rr(stacks, 2));
	else if (!ft_strcmp(cmd, "rra\n"))
		return (rra(stacks, 2));
	else if (!ft_strcmp(cmd, "rrb\n"))
		return (rrb(stacks, 2));
	else if (!ft_strcmp(cmd, "rrr\n"))
		return (rrr(stacks, 2));
	else
		return (0);
}

int	get_cmd(t_stack *stacks)
{
	char	*check;
	int		fd;
	int		i;

	i = 0;
	fd = 0;
	check = get_next_line(fd);
	while (check)
	{	
		if (check_cmd(check, stacks))
			free(check);
		else
			ft_error(stacks);
		check = get_next_line(fd);
	}
	free(check);
	return (1);
}
