/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_child_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:49:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/18 19:04:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				insert_child_node(t_fn *parent, t_fn *child)
{
	if (parent->child)
		insert_node_in_rootlist(parent->child, child);
	else
	{
		child->left = child;
		child->right = child;
		parent->child = child;
	}
	child->parent = parent;
	if (child->degree + 1 > parent->degree)
		parent->degree = child->degree + 1;
}
