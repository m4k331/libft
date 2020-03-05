/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:43:29 by ahugh             #+#    #+#             */
/*   Updated: 2019/12/02 17:17:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vmap(t_vector *v, long with_iterate, int (*map)(void*))
{
	void			*elem;

	v->iter = with_iterate - 1;
	elem = ft_vnext_con(v);
	while (elem)
	{
		if (map(elem) == FALSE)
			return (FALSE);
		elem = ft_vnext_con(v);
	}
	return (TRUE);
}
