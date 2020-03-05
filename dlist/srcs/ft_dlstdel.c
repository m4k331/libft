/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 14:57:24 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/04 19:26:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdel(t_dlist **dlst, void (*del)(void*, size_t))
{
	t_dlist			*next;

	if (dlst && del)
	{
		while (*dlst)
		{
			next = (*dlst)->next;
			ft_dlstdelone(dlst, del);
			*dlst = next;
		}
	}
}
