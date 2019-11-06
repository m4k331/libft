/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictresize.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 17:13:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 22:38:07 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	data_transfer(t_dict *dst, t_dict *src)
{
	char			*key;
	void			*value;

	src->keys->iter = -1;
	while (src->keys->iter < src->keys->head)
	{
		key = ft_vnext_con(src->keys);
		value = ft_dictget(src, key);
		ft_dictset(dst, key, value);
	}
}

static inline int	resize(t_dict *dict, size_t size)
{
	t_dict			*new_dict;

	if (dict == NULL)
		return (FALSE);
	new_dict = ft_dictnew(size);
	if (new_dict == NULL)
		return (FALSE);
	data_transfer(new_dict, dict);
	ft_dictdel(&dict, NULL);
	dict = new_dict;
	return (TRUE);
}

int					ft_dictresize(t_dict *dict, int grow)
{
	if (grow)
		return (resize(dict, GROW_RATE(dict)));
	else
		return (resize(dict, REDUCE_RATE(dict)));
}
