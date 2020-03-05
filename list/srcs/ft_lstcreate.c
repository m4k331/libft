/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstcreate.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/06 09:20:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:02:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstcreate(size_t size)
{
	t_list			*head;
	t_list			*iter;
	size_t			count;

	if (size == 0)
		return (NULL);
	head = ft_lstnew(0, 0);
	if (head == NULL)
		return (NULL);
	iter = head;
	count = 0;
	while (count < size)
	{
		iter->next = ft_lstnew(0, 0);
		if (iter->next == NULL)
		{
			ft_lstdel(&head, ft_delcontent);
			return (NULL);
		}
		iter = iter->next;
		count++;
	}
	return (head);
}
