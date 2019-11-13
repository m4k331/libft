/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node_to_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:07:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 21:51:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			vdel(void *v)
{
	ft_vdel((t_vector**)v);
}

int					del_node_to_dictionary(t_fib *fib, t_fn *node)
{
	t_vector		**vvals;
	t_vector		*vec;
	char			*key;
	void			**vnode;
	void			**ft;

	key = ft_itoa_base((uint64_t)node->value, 16);
	if (key == NULL)
		return (FALSE);
	vvals = ft_dictget(fib->values, key);
	if (vvals == NULL)
	{
		ft_memdel((void**)&key);
		return (FALSE);
	}
	vec = *vvals;
	vec->iter = -1;
	while (vec->iter < vec->head)
	{
		vnode = ft_vnext_con(vec);
		if (node == *vnode)
		{
			ft = ft_vpop_back(vec);
			*vnode = *ft;
			if (vec->head == 0)
				ft_dictunset(fib->values, key, vdel);
			else
				ft_memdel((void**)&key);
			return (TRUE);
		}
	}
	ft_memdel((void**)&key);
	return (FALSE);
}
