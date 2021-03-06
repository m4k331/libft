/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_slotsdel.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:03:09 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/18 19:04:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	slotdel(t_slot *slot, void del(void*))
{
	if (slot)
	{
		if (slot->key)
		{
			ft_memdel((void**)&slot->key);
			if (slot->value && del)
				del(&slot->value);
		}
		free(slot);
	}
}

void				ft_slotsdel(t_slot ***slots, void del(void*), size_t length)
{
	t_slot			**tape;
	size_t			iter;

	tape = *slots;
	iter = 0;
	while (iter < length)
	{
		slotdel(tape[iter], del);
		iter++;
	}
	ft_memdel((void**)slots);
	*slots = NULL;
}
