/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slotsnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:42:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 03:11:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slot			**ft_slotsnew(size_t length)
{
	t_slot		**slots;
	size_t		iter;

	slots = (t_slot**)malloc(sizeof(t_slot*) * length);
	if (slots == NULL)
		return (NULL);
	iter = 0;
	while (iter < length)
	{
		slots[iter] = (t_slot*)ft_memalloc(sizeof(t_slot));
		if (slots[iter] == NULL)
		{
			ft_slotsdel(&slots, NULL, iter);
			return (NULL);
		}
		iter++;
	}
	return (slots);
}
