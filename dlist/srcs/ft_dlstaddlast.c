/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstaddlast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:33:39 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 13:44:41 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstaddlast(t_dlist **dlst, t_dlist *new)
{
	t_dlist			*last;

	last = ft_dlstlast(*dlst);
	last->next = new;
	new->prev = last;
	new->next = NULL;
}
