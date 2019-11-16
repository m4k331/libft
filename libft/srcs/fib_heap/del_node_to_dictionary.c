/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node_to_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:07:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/14 19:37:00 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			vdel(void *v)
{
	ft_vdel((t_vector**)&v);
}

int					del_node_to_dictionary(t_fib *fib, t_fn *node)
{
	t_vector		*vvals;
	char			*key;
	void			*vnode;
	size_t			pop;
	void			*curr;

	key = ft_itoa_base((uint64_t)node->value, 16);
	if (key == NULL)
		return (FALSE);
	vvals = ft_dictget(fib->values, key);
	if (vvals == NULL)
	{
		ft_memdel((void**)&key);
		return (FALSE);
	}
//	printf("%zx\n", *(size_t*)vvals->con);
	vvals->iter = -1;
	while (vvals->iter < vvals->head)
	{
		vnode = *(void**)ft_vnext_con(vvals);
		printf("\t%p\n", vnode);
		if (node == vnode)
		{
			pop = *(size_t*)ft_vpop_back(vvals);
			if (pop != (size_t)vnode)
			{
//				printf("pop = %zx\nvnode = %p\n", pop, vnode);
				curr = ft_vcurr_con(vvals);
//				printf("A:curr = %zx\n", *(size_t*)curr);
				*(size_t*)curr = pop;
//				printf("B:curr = %zx\n", *(size_t*)curr);
//				printf("v->con = %zx\n", *(size_t*)vvals->const_con);
			}
			if (vvals->head == 0)
				ft_dictunset(fib->values, key, vdel);
			else
				ft_memdel((void**)&key);
			return (TRUE);
		}
	}
	ft_memdel((void**)&key);
	return (FALSE);
}
