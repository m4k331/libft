/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpop_back.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 22:57:24 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 13:56:59 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_vpop_back(t_vector *v)
{
	void	*element;

	element = NULL;
	if (v && v->head)
	{
		v->head--;
		element = (void*)(v->const_con + v->type_size * v->head);
	}
	return (element);
}
