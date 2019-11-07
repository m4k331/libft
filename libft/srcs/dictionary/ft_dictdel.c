/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:53:22 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 03:11:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_dictdel(t_dict **dict, void del(void*))
{
	t_dict		*d;

	d = *dict;
	if (d)
	{
		if (d->table)
			ft_slotsdel(&(d->table), del, d->mask);
		if (d->keys)
			ft_vdel(&(d->keys));
		if (d->items)
			ft_vdel(&(d->items));
		ft_memdel((void**)dict);
	}
}
