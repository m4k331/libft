/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictnext_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/25 18:08:13 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/25 18:34:47 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_dictnext_key(t_dict *dict)
{
	char		*key;
	long		count;

	key = ft_vnext_con(dict->keys);
	count = dict->keys->head - dict->keys->iter;
	if (count > 0)
		while (count-- && *(size_t*)key == 0)
			key = ft_vnext_con(dict->keys);
	return (key);
}
