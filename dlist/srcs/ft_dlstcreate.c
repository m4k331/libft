/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcreate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:11:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:11:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstcreate(size_t size)
{
	t_dlist			*head;
	t_dlist			*iter;
	size_t			count;

	if (size == 0)
		return (NULL);
	head = ft_dlstnew(0, 0);
	if (head == NULL)
		return (NULL);
	iter = head;
	count = 0;
	while (count < size)
	{
		iter->next = ft_dlstnew(0, 0);
		if (iter->next == NULL)
		{
			ft_dlstdel(&head, ft_delcontent);
			return (NULL);
		}
		(iter->next)->prev = iter;
		iter = iter->next;
		count++;
	}
	return (head);
}
