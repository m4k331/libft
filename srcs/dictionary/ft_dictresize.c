/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictresize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:13:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/24 06:31:26 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	reindexing(t_dict *dst, t_dict *src)
{
	t_slot			*slot;
	size_t			hash;
	char			*key;

	src->keys->iter = -1;
	key = ft_vnext_con(src->keys);
	while (src->keys->iter < src->keys->head)
	{
		if (*(size_t*)key)
		{
			hash = ft_hash(key);
			slot = ft_lookup(src, hash, key, FALSE);
			insert_values_in_dict(dst, slot->key, slot->value);
			slot->key = NULL;
		}
		key = ft_vnext_con(src->keys);
	}
}

static inline void	data_transfer(t_dict *dict, t_dict *tmp)
{
	t_slot			**table;
	t_vector		*keys;
	t_vector		*items;
	size_t			mask;

	reindexing(tmp, dict);
	table = dict->table;
	keys = dict->keys;
	items = dict->items;
	mask = dict->mask;
	dict->mask = tmp->mask;
	dict->used = tmp->used;
	dict->fill = tmp->fill;
	dict->table = tmp->table;
	dict->keys = tmp->keys;
	dict->items = tmp->items;
	tmp->table = table;
	tmp->keys = keys;
	tmp->items = items;
	tmp->mask = mask;
}

static inline int	resize(t_dict *dict, size_t size)
{
	t_dict			*tmp;

	if (dict == NULL)
		return (FALSE);
	tmp = ft_dictnew(size);
	if (tmp == NULL)
		return (FALSE);
	data_transfer(dict, tmp);
	ft_dictdel(&tmp, NULL);
	return (TRUE);
}

int					ft_dictresize(t_dict *dict, int grow)
{
	if (grow)
		return (resize(dict, GROW_RATE(dict)));
	else
		return (resize(dict, REDUCE_RATE(dict)));
}
