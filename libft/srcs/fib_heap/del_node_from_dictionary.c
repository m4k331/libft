/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_node_from_dictionary.c                         :+:      :+:    :+:   */
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

static inline int	delete_require_node(t_fib *fib, \
										t_fn *req_node, \
										t_vector *vector_nodes, \
										char *key)
{
	void			*node;
	size_t			address_value;
	void			*curr;

	vector_nodes->iter = -1;
	while (vector_nodes->iter < vector_nodes->head)
	{
		node = *(void**)ft_vnext_con(vector_nodes);
		if (req_node == node)
		{
			address_value = *(size_t*)ft_vpop_back(vector_nodes);
			if (address_value != (size_t)node)
			{
				curr = ft_vcurr_con(vector_nodes);
				*(size_t*)curr = address_value;
			}
			if (vector_nodes->head == 0)
				ft_dictunset(fib->values, key, vdel);
			return (TRUE);
		}
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
