/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 12:06:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:02:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list			*ft_lstjoin(t_list *alst, t_list *blst)
{
	t_list			*last_in_head;
	t_list			*head;
	t_list			*tail;

	head = ft_lstcopy(alst);
	if (head == NULL)
		return (NULL);
	tail = ft_lstcopy(blst);
	if (tail == NULL)
	{
		ft_lstdel(&head, ft_delcontent);
		return (NULL);
	}
	last_in_head = ft_lstlast(head);
	last_in_head->next = tail;
	return (head);
}
