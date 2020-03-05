/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:34:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 22:05:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					add_node_to_dictionary(t_fib *fib, t_fn *node)
{
	t_vector		*vector_nodes;

	update_fib_key_buffer(fib->key_buffer, (size_t)node->value);
	vector_nodes = ft_dictget(fib->values, fib->key_buffer);
	if (vector_nodes == NULL)
	{
		vector_nodes = ft_vnew(sizeof(void*) * DICT_MINSIZE, sizeof(void*));
		if (vector_nodes == NULL)
			return (FALSE);
		if (ft_dictset(fib->values, fib->key_buffer, vector_nodes) == FALSE)
		{
			ft_vdel(&vector_nodes);
			return (FALSE);
		}
	}
	return (ft_vpush_back(vector_nodes, &node, sizeof(void*)));
}
