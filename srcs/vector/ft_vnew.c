/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:05:48 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 12:50:47 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		*ft_vnew(long v_size, long type_size)
{
	t_vector	*v;

	v = (t_vector*)malloc(sizeof(t_vector));
	if (v && v_size && type_size)
	{
		v->type_size = type_size;
		v->size = v_size;
		v->head = 0;
		v->iter = 0;
		v->const_con = (const void*)malloc(v_size);
		if (v->const_con)
			v->con = (void*)v->const_con;
		else
			ft_memdel((void**)&v);
	}
	return (v);
}
