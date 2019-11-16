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
	v = NULL;
}

static inline int	delete_require_node(t_fib *fib, \
										t_fn *req_node, \
										t_vector *vector_nodes, \
										char **key)
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
				ft_dictunset(fib->values, *key, vdel);
			ft_memdel((void**)key);
			return (TRUE);
		}
	}
	ft_memdel((void**)key);
	return (FALSE);
}

int					del_node_to_dictionary(t_fib *fib, t_fn *req_node)
{
	t_vector		*vector_nodes;
	char			*key;

	key = ft_itoa_base((uint64_t)req_node->value, 16);
	if (key == NULL)
		return (FALSE);
	vector_nodes = ft_dictget(fib->values, key);
	if (vector_nodes == NULL)
	{
		ft_memdel((void**)&key);
		return (FALSE);
	}
	return (delete_require_node(fib, req_node, vector_nodes, &key));
}
