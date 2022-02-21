/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:42:20 by mmargene          #+#    #+#             */
/*   Updated: 2021/12/27 14:10:35 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_find_char(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*str;
	size_t	i;
	size_t	la;
	size_t	lz;

	la = 0;
	if (!s1)
		return (NULL);
	while (s1[la] && ft_find_char(s1[la], set))
		la++;
	lz = ft_strlen(s1);
	while (la < lz && ft_find_char(s1[lz - 1], set))
		lz--;
	str = (char *)malloc(sizeof(*s1) * (lz - la + 1));
	if (!str)
		return (NULL);
	i = 0;
	while (la < lz)
	{
		str[i] = s1[la];
		i++;
		la++;
	}
	str[i] = 0;
	return (str);
}
