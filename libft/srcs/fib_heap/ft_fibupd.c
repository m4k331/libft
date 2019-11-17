/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibupd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 13:17:36 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/17 23:27:33 by ahugh            ###   ########.fr       */
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
	else
		parent->child = node->right;
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

static inline t_fn	*get_node_with_old_val(t_fib *fib, void *old_value)
{
	t_vector		*vector_nodes;
	t_fn			*node;

	update_fib_key_buffer(fib->key_buffer, (size_t)old_value);
	vector_nodes = ft_dictget(fib->values, fib->key_buffer);
	if (vector_nodes == NULL || vector_nodes->head == 0)
		return (NULL);
	node = *(t_fn**)ft_vnext_con(vector_nodes);
	return (node);
}

void				*ft_fibupd(t_fib *fib, void *old_value, void *new_value)
{
	t_fn			*node;
	t_fn			*parent;

	if (fib->cmp(old_value, new_value) == TRUE)
		return (NULL);
	node = get_node_with_old_val(fib, old_value);
	if (node == NULL)
		return (NULL);
	node->value = new_value;
	if (add_node_to_dictionary(fib, &node) == FALSE)
		return (NULL);
	parent = node->parent;
	if (parent != NULL && fib->cmp(node->value, parent->value) == TRUE)
	{
		cut(fib, node, parent);
		cascading_cut(fib, parent);
	}
	if (fib->cmp(node->value, fib->priority) == TRUE)
		fib->priority = node;
	return (old_value);
}
