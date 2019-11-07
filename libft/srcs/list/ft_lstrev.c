/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:15:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:36:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstrev(t_list **alst)
{
	t_list		*last;
	t_list		*curr;
	t_list		*next;

	last = 0;
	if (alst && *alst)
	{
		curr = *alst;
		next = (*alst)->next;
		while (next)
		{
			curr->next = last;
			last = curr;
			curr = next;
			next = next->next;
		}
		curr->next = last;
		*alst = curr;
	}
}
