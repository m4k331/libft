/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:34:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/17 22:44:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	add_node_in_old_vector(t_vector *v, t_fn **n)
{
	if (ft_vpush_back(v, n, VOID_SIZE) == FALSE)
		return (FALSE);
	return (TRUE);
}

static inline int	set_node_in_new_vector(t_fib *f, t_fn **n, char *k)
{
	t_vector		*v;

	v = ft_vnew(VOID_SIZE * DICT_MINSIZE, VOID_SIZE);
	if (v == NULL)
		return (FALSE);
	if (ft_dictset(f->values, k, v) == FALSE)
	{
		ft_vdel(&v);
		return (FALSE);
	}
	if (ft_vpush_back(v, n, VOID_SIZE) == FALSE)
		return (FALSE);
	return (TRUE);
}

int 				add_node_to_dictionary(t_fib *fib, t_fn **node)
{
	void			*vector_nodes;

	update_fib_key_buffer(fib->key_buffer, (size_t)(*node)->value);
	vector_nodes = ft_dictget(fib->values, fib->key_buffer);
	return (vector_nodes == NULL ? \
			set_node_in_new_vector(fib, node, fib->key_buffer) : \
			add_node_in_old_vector(vector_nodes, node));
}
