/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_child_node.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 20:49:01 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 20:53:07 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				insert_child_node(t_fn *parent, t_fn *child)
{
	if (parent->child)
		insert_node_in_rootlist(parent->child, child);
	else
	{
		child = create_rootlist(&child, 1);
		parent->child = child;
	}
	child->parent = parent;
	if (child->degree + 1 > parent->degree)
		parent->degree = child->degree + 1;
}
