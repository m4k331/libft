/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_priority.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 12:31:53 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 12:55:08 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	add_child_nodes_in_rootlist(t_fib *fib, t_fn *child)
{
	t_fn			*unbind;
	t_fn			*next;
	t_fn			*last;

	last = child->left;
	while (TRUE)
	{
		next = child->right;
		unbind = unbind_node(child);
		insert_node_in_rootlist(fib->priority, unbind);
		if (child == last)
			break ;
		child = next;
	}
}

t_fn				*extract_priority(t_fib *fib)
{
	t_fn			*prior;

	prior = fib->priority;
	if (prior->child)
		add_child_nodes_in_rootlist(fib, prior->child);
	fib->priority = ((prior->right == prior) ? NULL : prior->right);
	unbind_node(prior);
	return (prior);
}
