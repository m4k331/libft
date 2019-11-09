/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictiterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:34:06 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 20:50:58 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dictiterate(t_dict *dict, int map(void*))
{
	size_t		iter;
	void		*item;

	dict->items->iter = -1;
	iter = 0;
	while (iter < dict->used)
	{
		item = ft_vnext_con(dict->items);
		while (item == NULL)
			item = ft_vnext_con(dict->items);
		if (map(item) == FALSE)
			return (FALSE);
		iter++;
	}
	return (TRUE);
}

