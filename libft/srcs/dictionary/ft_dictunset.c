/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictunset.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 16:14:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 20:46:11 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	unset(t_vector *keys, size_t ix, size_t size)
{
	void			*ptr;

	ptr = ft_vat(keys, ix);
	if (ptr)
		ft_bzero(ptr, size);
}

int					ft_dictunset(t_dict *dict, char *key, void del(void*))
{
	t_slot			*slot;
	size_t			hash;
	size_t			index;

	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key, FALSE);
	if (slot->value == NULL)
		return (FALSE);
	index = DKIX(slot->ix);
	unset(dict->items, index, VOID_SIZE);
	unset(dict->keys, index, DK_SIZE);
	slot->ix = MASK_DUMMY | DKIX(slot->ix);
	ft_memdel((void**)&slot->key);
	if (del)
		del(slot->value);
	dict->used--;
	return (TRUE);
}
