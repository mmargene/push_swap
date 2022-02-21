/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:39:12 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/12 01:51:53 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	if (c == ' ' || c == '\n' || c == '\t' \
	|| c == '\v' || c == '\f' || c == '\r')
		return (1);
	else
		return (0);
}

int	ft_atoi(const char *str)
{
	size_t	n;
	int		negative;
	int		i;

	i = 0;
	n = 0;
	negative = 1;
	if (ft_isalpha(str[i]))
		return (0);
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			negative = -1;
	while ((str[i]) && (ft_isdigit(str[i])))
	{
		n = 10 * n + (str[i] - 48);
		if ((negative == -1) && (n > 2147483648))
			return (0);
		if ((negative == 1) && (n > 2147483647))
			return (-1);
		i++;
	}
	return ((int)n * negative);
}
