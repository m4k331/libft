/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:34:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/23 23:06:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	duplicate_key(char **dup_key, char *key)
{
	*dup_key = ft_strnew(DK_SIZE);
	if (*dup_key == NULL)
		return (FALSE);
	ft_strcpy(*dup_key, key);
	return (TRUE);
}

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
	ft_vpush_back(dict->keys, key, DK_SIZE);
}

static inline void	set_items(t_dict *dict, t_slot *slot, void *value)
{
	slot->value = value;
	ft_vpush_back(dict->items, &value, VOID_SIZE);
}

int					ft_dictset(t_dict *dict, char *key, void *value)
{
	size_t			hash;
	t_slot			*slot;
	char			*dup_key;

	printf("%p\n", value);
	if (dict == NULL || key == NULL || value == NULL)
		return (FALSE);
	if (duplicate_key(&dup_key, key) == FALSE)
		return (FALSE);
	if (dict->fill > USABLE(dict->mask) && ft_dictresize(dict, TRUE) == FALSE)
	{
		ft_memdel((void**)&dup_key);
		return (FALSE);
	}
	hash = ft_hash(dup_key);
	slot = ft_lookup(dict, hash, dup_key, TRUE);
	set_ix(dict, slot);
	set_keys(dict, slot, dup_key);
	set_items(dict, slot, value);
	slot->hash = hash;
	return (TRUE);
}
