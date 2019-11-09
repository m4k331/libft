/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictunset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:14:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 17:21:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	unset_items(t_vector *items, size_t ix)
{
	void			*pitems;

	pitems = ft_vat(items, ix);
	ft_bzero(pitems, VOID_SIZE);
}

static inline void	unset_keys(t_vector *keys, size_t ix)
{
	void			*pkey;

	pkey = ft_vat(keys, ix);
	ft_bzero(pkey, DK_SIZE);
}

void			ft_dictunset(t_dict *dict, char *key, void del(void*))
{
	t_slot		*slot;
	size_t		hash;
	size_t		index;

	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key, FALSE);
	index = DKIX(slot->ix);
	unset_items(dict->items, index);
	unset_keys(dict->keys, index);
	slot->ix = DKIX_DUMMY(slot->ix);
	ft_memdel((void**)&slot->key);
	del(slot->value);
}
