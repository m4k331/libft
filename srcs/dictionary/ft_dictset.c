/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:34:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 14:32:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		insert_value(t_dict *dict, size_t hash, char *key, void *value)
{
	if (USABLE_FRACTION(dict->fill))
	{

	}
}

int				ft_dictset(t_dict *dict, char *key, void *value)
{
	size_t		hash;
	t_slot		*slot;

	if (dict == NULL || key == NULL || value == NULL)
		return (FALSE);
	hash = ft_hash(key);
	slot = ft_lookup(dict, hash, key);

}
