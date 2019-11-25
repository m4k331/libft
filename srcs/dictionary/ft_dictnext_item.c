/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnext_item.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:09:23 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/25 18:29:47 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_dictnext_item(t_dict *dict)
{
	void		*item;
	long		count;

	item = ft_vnext_con(dict->items);
	count = dict->items->head - dict->items->iter;
	if (count > 0)
		while (*(size_t*)item == 0 && count--)
			item = ft_vnext_con(dict->items);
	return (item);
}
