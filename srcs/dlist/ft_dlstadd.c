/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:12:09 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 13:28:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstadd(t_dlist **dlst, t_dlist *new)
{
	if (*dlst && new)
	{
		new->next = *dlst;
		new->prev = (*dlst)->prev;
		(*dlst)->prev = new;
		*dlst = new;
	}
}
