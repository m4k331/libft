/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dictiterate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/09 20:34:06 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/23 22:43:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_dictiterate(t_dict *dict, int map(void*))
{
	void		*item;

	dict->items->iter = -1;
	item = ft_dictnext_item(dict);
	while (item)
	{
		if (map(item) == FALSE)
			return (FALSE);
		item = ft_dictnext_item(dict);
	}
	return (TRUE);
}
