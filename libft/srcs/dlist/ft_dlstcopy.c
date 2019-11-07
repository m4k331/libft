/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstcopy.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:34:33 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:43:52 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstcopy(t_dlist *dlst)
{
	t_dlist			*head;
	t_dlist			*iter;

	if (dlst == NULL)
		return (NULL);
	head = ft_dlstnew(dlst->con, dlst->con_sz);
	if (head == NULL)
		return (NULL);
	iter = head;
	dlst = dlst->next;
	while (dlst)
	{
		iter->next = ft_dlstnew(dlst->con, dlst->con_sz);
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
