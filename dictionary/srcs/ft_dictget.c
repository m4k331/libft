/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictget.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 22:22:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 22:22:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_dictget(t_dict *dict, char *key)
{
	size_t		hash;
	t_slot		*slot;

	if (dict == NULL || key == NULL)
		return (NULL);
	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key, FALSE);
	if (slot)
		return (slot->value);
	return (NULL);
}
