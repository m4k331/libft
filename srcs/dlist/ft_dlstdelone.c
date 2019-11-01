/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:12:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 19:44:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdelone(t_dlist **dlst, void (*del)(void*, size_t))
{
	if (*dlst && del)
	{
		del((*dlst)->con, (*dlst)->con_sz);
		(*dlst)->next = NULL;
		(*dlst)->prev = NULL;
		ft_memdel((void **)dlst);
	}
}
