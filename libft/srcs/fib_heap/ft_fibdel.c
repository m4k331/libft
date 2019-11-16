/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:49:39 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 23:51:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			vdel(void *v)
{
//	printf("vdel: %p - %zx\n", v, *(size_t*)v);
	if (v)
	{
		ft_vdel((t_vector**)v);
		v = NULL;
	}
}

static inline void	destroy_heap(t_fn **roots, void del(void*))
{
	t_fn			*node;
	t_fn			*next;

	node = *roots;
	while (node)
	{
		if (node->child)
			destroy_heap(&node->child, del);
		next = node == node->right ? NULL : node->right;
//		printf("n:%p nxt:%p node->val = %ld node->right = %p\n", node, next, *(long*)node->value, node->right);
		unbind_node(node);
		fndel(&node, del);
		node = next;
	}
}

void				ft_fibdel(t_fib **fib)
{
	destroy_heap(&(*fib)->priority, (*fib)->del);
	ft_dictdel(&(*fib)->values, vdel);
	ft_memdel((void**)fib);
}
