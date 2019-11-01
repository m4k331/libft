/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:57:24 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/01 18:40:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_vpop_back(t_vector *v)
{
	void			*element;

	element = NULL;
	if (v->head)
	{
		v->head--;
		element = (void*)(((char*)v->con) + v->type_size * (v->head - 1));
	}
	return (element);
}
