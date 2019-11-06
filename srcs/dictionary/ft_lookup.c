/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:04:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 14:04:11 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_lookup(t_dict *dict, size_t hash)
{
	size_t		perturb;
	size_t		i;

	perturb = hash;
	i = hash & dict->mask;
	while (TRUE)
	{
		if (DKIX_DUMMY(dict->table[i]->ix) || DKIX_EMPTY(dict->table[i]->ix))
			return (i);
		if (dict->table[i]->hash == hash)
			return (i);
		perturb >>= PERTURB_SHIFT;
		i = (i * 5 + perturb + 1) & dict->mask;
	}
}
