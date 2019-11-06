/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictresize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:13:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 19:14:55 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	table_resize(t_dict *dict, size_t size)
{

}

static inline int	resize(t_dict *dict, size_t size)
{
	void			*keys;
	void			*items;

	old_keys = dict->keys;
	if (ft_vresize(dict->keys, (long)size * dict->keys->type_size) == FALSE)
		return (FALSE);
	old_items = dict->items;
	if (ft_vresize(dict->items, (long)size * dict->items->type_size) == FALSE)
		return (FALSE);
	return (TRUE);
}

int					ft_dictresize(t_dict *dict, int grow)
{
	if (grow)
		return (resize(dict, GROW_RATE(dict)));
	else
		return (resize(dict, REDUCE_RATE(dict)));
}
