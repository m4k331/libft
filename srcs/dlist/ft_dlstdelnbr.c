/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelnbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:46:57 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:59:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_dlstdelnbr(t_dlist **dlst, void (*del)(void*, size_t), size_t n)
{
	t_dlist	*target;
	t_dlist	*prev;
	t_dlist	*next;

	target = ft_dlstat(*dlst, n);
	if (target == NULL || del == NULL)
		return ;
	prev = target->prev;
	next = target->next;
	ft_dlstdelone(&target, del);
	if (prev == NULL)
	{
		*dlst = next;
		return ;
	}
	prev->next = next;
}
