/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictkeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:03:14 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 03:36:37 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_dictkeys(t_dict *dict)
{
	char			**keys;
	char			*key;
	char			*dup_key;
	long			iter;

	keys = (char**)ft_memalloc((dict->used + 1) * sizeof(char*));
	if (keys == NULL)
		return (NULL);
	iter = 0;
	dict->keys->iter = -1;
	key = ft_dictnext_key(dict);
	while (key)
	{
		if (duplicate_key(&dup_key, key) == FALSE)
		{
			del_any_matrix((void**)keys, 2);
			return (NULL);
		}
		keys[iter] = dup_key;
		key = ft_dictnext_key(dict);
		iter++;
	}
	return (keys);
}
