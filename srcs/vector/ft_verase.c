/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verase.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 20:24:58 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 21:25:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_verase(t_vector *v)
{
	if (v)
	{
		if (v->const_con)
		{
			ft_bzero((void*)v->const_con, v->size);
			ft_memdel((void**)&v->const_con);
		}
		v->con = (void*)v->const_con;
		v->head = 0;
		v->size = 0;
		v->iter = 0;
		v->type_size = 0;
	}
}
