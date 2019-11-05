/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dictdel.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 16:53:22 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 18:42:01 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dictdel(t_dict **dict, void del(void*))
{
	if (*dict)
	{
		if ((*dict)->table)
			ft_slotsdel(&((*dict)->table), del, (*dict)->mask);
		if ((*dict)->keys)
			ft_vdel(&((*dict)->keys));
		if ((*dict)->items)
			ft_vdel(&((*dict)->items));
		ft_memdel((void**)dict);
	}
}
