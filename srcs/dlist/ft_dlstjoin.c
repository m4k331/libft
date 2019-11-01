/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:28:26 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:57:17 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstjoin(t_dlist *adlst, t_dlist *bdlst)
{
	t_dlist			*last_in_head;
	t_dlist			*head;
	t_dlist			*tail;

	head = ft_dlstcopy(adlst);
	if (head == NULL)
		return (NULL);
	tail = ft_dlstcopy(bdlst);
	if (tail == NULL)
	{
		ft_dlstdel(&head, ft_delcontent);
		return (NULL);
	}
	last_in_head = ft_dlstlast(head);
	last_in_head->next = tail;
	tail->prev = last_in_head;
	return (head);
}
