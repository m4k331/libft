/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcopy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:43:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:52:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstcopy(t_list *lst)
{
	t_list			*head;
	t_list			*iter;

	if (lst == NULL)
		return (NULL);
	head = ft_lstnew(lst->content, lst->content_size);
	if (head == NULL)
		return (NULL);
	iter = head;
	lst = lst->next;
	while (lst)
	{
		iter->next = ft_lstnew(lst->content, lst->content_size);
		if (iter->next == NULL)
		{
			ft_lstdel(&head, ft_delcontent);
			return (NULL);
		}
		iter = iter->next;
		lst = lst->next;
	}
	return (head);
}
