/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_values_in_dict.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/24 05:07:36 by ahugh             #+#    #+#             */
/*   Updated: 2020/02/06 19:59:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				insert_values_in_dict(t_dict *dict, char *key, void *value)
{
	t_slot			*slot;
	size_t			hash;
	size_t			index;

	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key, TRUE);
	slot->hash = hash;
	slot->key = key;
	slot->value = value;
	if ((slot->ix & MASK_DUMMY) != 0)
	{
		dict->used++;
		index = (slot->ix & MASK_INDICES);
		ft_memcpy(ft_vat(dict->keys, index), key, DK_SIZE);
		ft_memcpy(ft_vat(dict->items, index), &value, sizeof(void**));
		slot->ix = MASK_ACTIVE | index;
	}
	if (slot->ix == 0)
	{
		dict->used++;
		dict->fill++;
		slot->ix = MASK_ACTIVE | (size_t)dict->keys->head;
		ft_vpush_back(dict->keys, key, DK_SIZE);
		ft_vpush_back(dict->items, &value, sizeof(void**));
	}
}
