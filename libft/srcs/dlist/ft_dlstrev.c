/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstrev.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:22:00 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:32:14 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstrev(t_dlist **dlst)
{
	t_dlist			*next;
	t_dlist			*prev;

	prev = NULL;
	while (*dlst)
	{
		next = (*dlst)->next;
		(*dlst)->next = (*dlst)->prev;
		(*dlst)->prev = next;
		prev = *dlst;
		*dlst = next;
	}
	*dlst = prev;
}
