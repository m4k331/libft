/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictkeys.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 18:03:14 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/27 18:37:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char				**ft_dictkeys(t_dict *dict)
{
	char			**keys;
	char			*key;
	char			*dup_key;
	long			iter;

	keys = (char**)ft_memalloc(dict->used * sizeof(char*));
	if (keys == NULL)
		return (NULL);
	dict->keys->iter = -1;
	key = ft_dictnext_key(dict);
	iter = 0;
	while (key)
	{
		key = ft_dictnext_key(dict);
		dup_key = ft_strdup(key);
		if (dup_key == NULL)
		{
			ft_arrdel((void**)keys);
			return (NULL);
		}
		keys[iter] = dup_key;
		iter++;
	}
	return (keys);
}
