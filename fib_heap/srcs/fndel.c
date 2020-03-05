/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fndel.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:32:09 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/18 19:04:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				fndel(t_fn **node, void del(void*))
{
	if (node && *node)
	{
		if ((*node)->value)
		{
			if (del)
				del((*node)->value);
			(*node)->value = NULL;
		}
		ft_memdel((void**)node);
	}
}
