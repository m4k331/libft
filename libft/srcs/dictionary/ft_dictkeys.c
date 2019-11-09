/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictkeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:03:14 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 19:49:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	del_table(void **table, size_t len)
{
	size_t			iter;

	iter = 0;
	while (iter < len)
	{
		ft_memdel((void**)&table[iter]);
		iter++;
	}
}

static inline void	**allocate_keytable(size_t len)
{
	void			**table;
	size_t			iter;

	table = (void**)malloc(sizeof(void*) * len);
	if (table == NULL)
		return (NULL);
	iter = 0;
	while (iter < len)
	{
		table[iter] = (void*)malloc(DK_SIZE);
		if (table[iter] == NULL)
		{
			del_table(table, iter);
			ft_memdel((void**)&table);
			return (NULL);
		}
		iter++;
	}
	return (table);
}

static inline void	fill_keytable(void **table, t_vector *keys, size_t len)
{
	char			*key;
	size_t			iter;

	iter = 0;
	keys->iter = -1;
	while (iter < len)
	{
		key = ft_vnext_con(keys);
		while (key == NULL)
			key = ft_vnext_con(keys);
		ft_memcpy(table[iter], key, DK_SIZE);
		iter++;
	}
}

void				**ft_dictkeys(t_dict *dict)
{
	void			**keys;

	keys = allocate_keytable(dict->used);
	if (keys == NULL)
		return (NULL);
	fill_keytable(keys, dict->keys, dict->used);
	return (keys);
}
