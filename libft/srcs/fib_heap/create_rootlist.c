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

static inline t_fn	*get_next_full_node(t_fn **nodes, size_t start, size_t end)
{
	size_t			i;

	i = start;
	while (i < end)
	{
		if (nodes[i])
			return (nodes[i]);
		i++;
	}
	return (NULL);
}

static inline void	delete_null_nodes(t_fn **nodes, size_t *len)
{
	size_t			i;

	i = 0;
	while (i < *len)
	{
		if (nodes[i] == NULL)
		{
			nodes[i] = get_next_full_node(nodes, i + 1, *len);
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
	right->left = first;
	first->right = right;
}

t_fn				*create_rootlist(t_fn **nodes, size_t len)
{
	delete_null_nodes(nodes, &len);
	bind_nodes(nodes, len);
	return (*nodes);
}
