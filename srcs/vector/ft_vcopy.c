/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vcopy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 19:27:54 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 19:46:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_vector			*ft_vcopy(t_vector *v)
{
	t_vector		*copy;

	copy = ft_vnew(v->size, v->type_size);
	if (copy == NULL)
		return (NULL);
	ft_memcpy(copy->con, v->const_con, ft_vsize(v));
	copy->const_con = (const void*)copy->con;
	copy->head = v->head;
	copy->iter = v->iter;
	return (copy);
}
