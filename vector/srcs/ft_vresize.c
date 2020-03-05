/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vresize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 18:37:57 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/20 15:33:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_vresize(t_vector *v, long v_size)
{
	const void	*con;
	long		copy_size;
	long		con_size;

	if (v == NULL || v_size == 0)
		return (FALSE);
	con = (const void*)malloc(v_size);
	if (con == NULL)
		return (FALSE);
	con_size = v->head * v->type_size;
	copy_size = v_size > con_size ? con_size : v_size;
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
