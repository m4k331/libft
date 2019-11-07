/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:25:38 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/07 05:45:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dict				*ft_dictnew(size_t size)
{
	t_dict			*dict;

	dict = (t_dict*)malloc(sizeof(t_dict));
	if (dict == NULL)
		return (NULL);
	dict->fill = 0;
	dict->used = 0;
	dict->mask = size < DICT_MINSIZE ? DICT_MINSIZE : size;
	dict->table = ft_slotsnew(dict->mask);
	dict->keys = ft_vnew((long)(dict->mask * DK_SIZE), DK_SIZE);
	dict->items = ft_vnew((long)(dict->mask * VOID_SIZE), VOID_SIZE);
	if (dict->table == NULL || dict->keys == NULL || dict->items == NULL)
		ft_dictdel(&dict, NULL);
	return (dict);
}
