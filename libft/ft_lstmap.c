/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmargene <mmargene@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 13:40:27 by mmargene          #+#    #+#             */
/*   Updated: 2021/12/27 13:40:28 by mmargene         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*cnt;

	if (!lst)
		return (NULL);
	if (!f)
		return (NULL);
	cnt = ft_lstnew(f(lst->content));
	if (!cnt)
		return (NULL);
	lst = lst->next;
	new = cnt;
	while (lst)
	{
		cnt = ft_lstnew(f(lst->content));
		if (!cnt)
		{
			ft_lstclear(&new, del);
			return (NULL);
		}
		lst = lst->next;
		ft_lstadd_back(&new, cnt);
	}
	return (new);
}
