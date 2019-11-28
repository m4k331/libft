/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictset.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:34:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/28 19:30:51 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	duplicate_key(char **dup_key, char *key)
{
	*dup_key = (char*)malloc((DK_SIZE + 1) * sizeof(char));
	if (*dup_key == NULL)
		return (FALSE);
	ft_memccpy(*dup_key, key, 0, DK_SIZE);
	(*dup_key)[DK_SIZE] = 0;
	return (TRUE);
}

int					ft_dictset(t_dict *dict, char *key, void *value)
{
	char			*dup_key;

	if (dict == NULL || key == NULL || value == NULL)
		return (FALSE);
	if (duplicate_key(&dup_key, key) == FALSE)
		return (FALSE);
	if (dict->fill > USABLE(dict->mask) && ft_dictresize(dict, TRUE) == FALSE)
	{
		ft_memdel((void**)&dup_key);
		return (FALSE);
	}
	insert_values_in_dict(dict, dup_key, value);
	return (TRUE);
}
