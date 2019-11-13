/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibupd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:17:36 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 13:17:36 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	cut(t_fib *fib, t_fn *node, t_fn *parent)
{
	if (node->right == node)
	{
		parent->degree--;
		parent->child = NULL;
	}
	node = unbind_node(node);
	node->mark = FALSE;
	insert_node_in_rootlist(fib->priority, node);
}

static inline void	cascading_cut(t_fib *fib, t_fn *node)
{
	t_fn			*parent;

	parent = node->parent;
	if (parent == NULL)
	{
		if (node->mark == FALSE)
			node->mark = TRUE;
		else
		{
			cut(fib, node, parent);
			cascading_cut(fib, parent);
		}
	}
}

int					ft_fibupd(t_fib *fib, t_fn *node, void *val)
{
	t_fn			*parent;

	if (fib->cmp(node->value, val) == TRUE)
		return (FALSE);
	fib->del(node->value);
	node->value = val;
	parent = node->parent;
	if (parent != NULL && fib->cmp(node->value, parent->value) == TRUE)
	{
		cut(fib, node, parent);
		cascading_cut(fib, parent);
	}
	else if (fib->cmp(node->value, fib->priority) == TRUE)
		fib->priority = node->value;
	return (TRUE);
}
