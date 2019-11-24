/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_values_in_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 05:07:36 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/24 06:12:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				insert_values_in_dict(t_dict *dict, char *key, void *value)
{
	size_t			hash;
	t_slot			*slot;
	size_t			index;

	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key, TRUE);
	slot->hash = hash;
	slot->key = key;
	slot->value = value;
	if (DKIX_DUMMY(slot->ix))
	{
		dict->used++;
		index = DKIX(slot->ix);
		ft_memcpy(ft_vat(dict->keys, index), key, DK_SIZE);
		ft_memcpy(ft_vat(dict->items, index), &value, sizeof(void**));
		slot->ix = MASK_ACTIVE | index;
	}
	if (DKIX_EMPTY(slot->ix))
	{
		dict->used++;
		dict->fill++;
		slot->ix = MASK_ACTIVE | (size_t)dict->keys->head;
		ft_vpush_back(dict->keys, key, DK_SIZE);
		ft_vpush_back(dict->items, &value, VOID_SIZE);
	}
}
