/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rootlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 13:17:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	replace_null_node(t_fn **nodes, size_t start, size_t end)
{
	size_t			i;

	i = start + 1;
	while (i < end)
	{
		if (nodes[i])
		{
			nodes[start] = nodes[i];
			nodes[i] = NULL;
			return ;
		}
		i++;
	}
	nodes[start] = NULL;
}

static inline void	delete_null_nodes(t_fn **nodes, size_t *len)
{
	size_t			i;

	i = 0;
	while (i < *len)
	{
		if (nodes[i] == NULL)
		{
			replace_null_node(nodes, i, *len);
			if (nodes[i] == NULL)
				break ;
		}
		i++;
	}
	*len = i;
}

static inline void	bind_nodes(t_fn **nodes, size_t len)
{
	size_t			i;
	t_fn			*first;
	t_fn			*left;
	t_fn			*right;

	i = 1;
	first = nodes[0];
	left = nodes[0];
	right = nodes[0];
	while (i < len)
	{
		if (nodes[i])
		{
			right = nodes[i];
			right->left = left;
			left->right = right;
			left = right;
		}
		i++;
	}
	right->right = first;
	first->left = right;
}

t_fn				*create_rootlist(t_fn **nodes, size_t len)
{
	delete_null_nodes(nodes, &len);
	bind_nodes(nodes, len);
	return (*nodes);
}
