/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:34:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 17:52:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	set_ix(t_dict *dict, t_slot *slot)
{
	if (DKIX_DUMMY(slot->ix))
	{
		dict->used++;
		slot->ix = MASK_ACTIVE | DKIX(slot->ix);
	}
	if (DKIX_EMPTY(slot->ix))
	{
		dict->used++;
		dict->fill++;
		slot->ix = MASK_ACTIVE | (size_t)dict->keys->head;
	}
}

static inline void	set_keys(t_dict *dict, t_slot *slot, char *key)
{
	slot->key = key;
	ft_vpush_back(dict->keys, key, sizeof(char*));
}

static inline void	set_items(t_dict *dict, t_slot *slot, char *value)
{
	slot->value = value;
	ft_vpush_back(dict->items, value, sizeof(void*));
}

int					ft_dictset(t_dict *dict, char *key, void *value)
{
	size_t			hash;
	t_slot			*slot;

	if (dict == NULL || key == NULL || value == NULL)
		return (FALSE);
	if (dict->fill > USABLE_FRACTION(dict->mask))
		if (ft_dictresize(dict, TRUE) == FALSE)
			return (FALSE);
	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key);
	set_ix(dict, slot);
	set_keys(dict, slot, key);
	set_items(dict, slot, value);
	slot->hash = hash;
	return (TRUE);
}
