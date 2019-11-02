/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:50:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 15:15:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_vat(t_vector *v, long position)
{
	long	shift;

	if (position < 0)
		position = v->head + position;
	if (v && position > -1)
	{
		shift = v->type_size * position;
		if (shift < ft_vsize(v))
			return ((void*)(v->const_con + shift));
	}
	return (NULL);
}
