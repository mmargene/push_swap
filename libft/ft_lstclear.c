/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:40:09 by mmargene          #+#    #+#             */
/*   Updated: 2021/12/27 13:40:10 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	while (*lst != NULL)
	{
		tmp = *lst;
		if (tmp->content)
		{
			del(tmp->content);
			tmp->content = NULL;
		}
		*lst = tmp->next;
		free(tmp);
	}
	lst = NULL;
}
