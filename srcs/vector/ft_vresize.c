/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:37:57 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/01 19:33:08 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_vresize(t_vector *v, size_t v_size)
{
	const void	*con;
	size_t		copy_size;

	if (v == NULL || v_size == 0)
		return (FALSE);
	con = (const void*)malloc(v_size);
	if (con == NULL)
		return (FALSE);
	copy_size = v_size > v->size ? v->size : v_size;
	ft_memcpy((void*)con, v->const_con, copy_size);
	if (v->const_con)
		ft_memdel((void**)&v->const_con);
	v->const_con = con;
	v->con = (void*)v->const_con;
	v->size = v_size;
	if (v->head * v->type_size > v->size)
		v->head = v->size / v->type_size;
	return (TRUE);
}
