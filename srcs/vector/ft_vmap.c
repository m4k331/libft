/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:43:29 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 22:00:09 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_vmap(t_vector *v, int (*map)(void*))
{
	void			*elem;

	elem = ft_vnext_con(v);
	while (elem)
	{
		if (map(elem) == FALSE)
			return (FALSE);
		elem = ft_vnext_con(v);
	}
	return (TRUE);
}
