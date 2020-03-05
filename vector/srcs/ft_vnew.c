/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnew.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:05:48 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 21:25:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector		*ft_vnew(long bytes_size, long type_size)
{
	t_vector	*v;

	if (bytes_size == 0 || type_size == 0)
		return (NULL);
	v = (t_vector*)malloc(sizeof(t_vector));
	if (v == NULL)
		return (NULL);
	v->type_size = type_size;
	v->size = bytes_size;
	v->head = 0;
	v->iter = -1;
	v->const_con = (const void*)malloc(bytes_size);
	if (v->const_con)
		v->con = (void*)v->const_con;
	else
		ft_memdel((void**)&v);
	return (v);
}
