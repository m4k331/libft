/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:34:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 23:29:02 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dictset(t_dict *dict, char *key, void *value)
{
	size_t		hash;
	size_t		perturb;
	size_t		i;

	if (dict == NULL || key == NULL || value == NULL)
		return (FALSE);
	hash = ft_hash(key);
	perturb = hash;
	i = hash & dict->mask;
	while (TRUE)
	{
		if (DKIX_DUMMY(dict->table[i]->ix) || DKIX_EMPTY(dict->table[i]->ix))
		{

		}
		if (DKIX_ERROR(dict->table[i]->ix))
			return (FALSE);
		perturb >>= PERTURB_SHIFT;
		i = (i*5 + perturb + 1) & mask;
	}
	return (TRUE);
}
