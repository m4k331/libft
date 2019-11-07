/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/03 16:20:36 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:52:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list*))
{
	t_list			*head;
	t_list			*iter;

	head = f(lst);
	if (head == NULL || lst == NULL)
		return (NULL);
	iter = head;
	lst = lst->next;
	while (lst)
	{
		iter->next = f(lst);
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
