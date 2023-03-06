/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mokatova <mokatova@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 16:37:00 by mokatova          #+#    #+#             */
/*   Updated: 2021/11/30 23:29:05 by mokatova         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*list;
	t_list	*link;

	if (!f || !del)
		return (NULL);
	list = NULL;
	while (lst)
	{
		link = ft_lstnew(f(lst->content));
		if (!link)
		{
			ft_lstclear(&link, del);
			return (NULL);
		}
		ft_lstadd_back(&list, link);
		lst = lst->next;
	}
	return (list);
}
