/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node_from_dictionary.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 17:07:12 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 22:38:00 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			vdel(void *v)
{
	ft_vdel((t_vector**)v);
}

static inline int	delete_require_node(t_fib *fib, \
										t_fn *req_node, \
										t_vector *vector_nodes, \
										char *key)
{
	void			**node;

	vector_nodes->iter = -1;
	node = ft_vnext_con(vector_nodes);
	while (node)
	{
		if (req_node == *(t_fn**)node)
		{
			ft_vpop_at(vector_nodes, vector_nodes->iter);
			if (vector_nodes->head == 0)
				ft_dictunset(fib->values, key, vdel);
			return (TRUE);
		}
		node = ft_vnext_con(vector_nodes);
	}
	return (FALSE);
}

int					del_node_from_dictionary(t_fib *fib, t_fn *req_node)
{
	t_vector		*vector_nodes;

	update_fib_key_buffer(fib->key_buffer, (size_t)req_node->value);
	vector_nodes = ft_dictget(fib->values, fib->key_buffer);
	if (vector_nodes == NULL)
		return (FALSE);
	return (delete_require_node(fib, req_node, vector_nodes, fib->key_buffer));
}
