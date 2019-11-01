/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vpush_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 17:32:17 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/01 19:35:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "stdio.h"

int			ft_vpush_back(t_vector *v, void *val, size_t val_size)
{
	size_t	free;
	size_t	old_size;

	if (v == NULL || val == NULL || val_size == 0)
		return (FALSE);
	free = v->size - v->head * v->type_size;
	old_size = v->size;
	if (val_size > free)
		while (old_size + val_size <= v->size)
			if (ft_vresize(v, v->size * EXPAND) == FALSE)
				return (FALSE);
	ft_memcpy((&v->con)[v->head], val, val_size);
	v->head += val_size / v->type_size;
	return (TRUE);
}
