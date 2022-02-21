/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:41:24 by mmargene          #+#    #+#             */
/*   Updated: 2022/01/13 04:18:17 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_cword(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			i++;
			while (*s && *s != c)
				s++;
		}
	}
	return (i);
}

static void	*ft_nword(char const **s, char c)
{
	char	*str;
	size_t	i;

	i = 0;
	while ((*s)[i] && (*s)[i] != c)
		i++;
	str = ft_substr(*s, 0, i);
	if (!str)
		return (NULL);
	*s = *s + i;
	return (str);
}

static void	*ft_fstr(char **new, size_t i)
{
	while (i--)
		free(new[i]);
	free(new);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**new;
	int		words;
	size_t	i;

	if (!s)
		return (NULL);
	words = ft_cword(s, c);
	new = (char **)malloc(sizeof(char *) * (words + 1));
	if (!new)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
		{
			new[i] = ft_nword(&s, c);
			if (new[i] == NULL)
				return (ft_fstr(new, i));
			i++;
		}
	}
	new[i] = NULL;
	return (new);
}
