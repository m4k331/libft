/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:56:25 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:43:52 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstmap(t_dlist *dlst, t_dlist *(*f)(t_dlist*))
{
	t_dlist			*head;
	t_dlist			*iter;

	head = f(dlst);
	if (head == NULL || dlst == NULL)
		return (NULL);
	iter = head;
	dlst = dlst->next;
	while (dlst)
	{
		iter->next = f(dlst);
		if (iter->next == NULL)
		{
			ft_dlstdel(&head, ft_delcontent);
			return (NULL);
		}
		(iter->next)->prev = iter;
		iter = iter->next;
		dlst = dlst->next;
	}
	return (head);
}
