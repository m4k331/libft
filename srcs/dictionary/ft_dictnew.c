/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:25:38 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 16:46:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict				*ft_dictnew(void)
{
	t_dict			*dict;

	dict = (t_dict*)malloc(sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	dict->fill = 0;
	dict->used = 0;
	dict->mask = DICT_MINSIZE;
	dict->table = (t_slot*)ft_memalloc(sizeof(t_slot) * DICT_MINSIZE);
	dict->keys = ft_vnew(GROW_RATE(dict), DK_SIZE);
	dict->items = ft_vnew(GROW_RATE(dict), sizeof(void*));
	if (dict->table == NULL || dict->keys == NULL || dict->items == NULL)
		ft_dictdel(&dict);
	return (dict);
}
