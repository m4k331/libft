/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lookup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 14:04:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/18 19:04:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_slot					*ft_lookup(t_dict *d, size_t hash, char *key, int set)
{
	size_t		perturb;
	size_t		i;
	size_t		mask;

	mask = d->mask - 1;
	perturb = hash;
	i = hash & mask;
	while (TRUE)
	{
		if ((DKIX_DUMMY(d->table[i]->ix) && set) || DKIX_EMPTY(d->table[i]->ix))
			return (d->table[i]);
		if (d->table[i]->hash == hash && ft_strcmp(d->table[i]->key, key) == 0)
			return (d->table[i]);
		perturb >>= PERTURB_SHIFT;
		i = (perturb ? i * 5 + perturb + 1 : i + 1) % mask;
	}
}
