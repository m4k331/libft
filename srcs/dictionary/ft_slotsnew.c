/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slotsnew.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 18:42:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 21:49:24 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slot				**ft_slotsnew(long length)
{
	t_slot			**slots;
	long			iter;

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
