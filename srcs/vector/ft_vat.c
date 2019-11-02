/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 21:50:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 13:18:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_vat(t_vector *v, size_t position)
{
	size_t	shift;

	if (v)
	{
		shift = v->type_size * position;
		if (shift < ft_vsize(v))
			return ((void*)(v->const_con + shift));
	}
	return (0);
}
