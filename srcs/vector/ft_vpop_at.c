/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_at.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 19:54:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 23:05:15 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_vpop_at(t_vector *v, long position)
{
	void			*element;
	void			*last_element;

	element = ft_vat(v, position);
	if (element == NULL)
		return (NULL);
	last_element = ((void*)v->const_con) + v->type_size * v->head;
	ft_memswap(&last_element, &element, v->type_size);
	v->head--;
	return (last_element);
}
