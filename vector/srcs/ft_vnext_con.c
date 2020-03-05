/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vnext_con.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/02 15:44:26 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 15:59:49 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		*ft_vnext_con(t_vector *v)
{
	if (v->iter < v->head)
	{
		v->iter++;
		return (ft_vcurr_con(v));
	}
	if (v->iter == v->head)
		v->iter++;
	return (NULL);
}
