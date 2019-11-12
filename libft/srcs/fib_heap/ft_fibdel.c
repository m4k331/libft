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

static inline void	destroy_heap(t_fn **roots, void del(void*))
{
	t_fn			*node;
	t_fn			*next;

	node = *roots;
	while(node)
	{
		if (node->child)
			destroy_heap(&node->child, del);
		next = node->right;
		fndel(&node, del);
		node = next;
	}
}

void				ft_fibdel(t_fib **fib)
{
	destroy_heap(&(*fib)->priority, (*fib)->del);
	ft_memdel((void**)fib);
}
