/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_rootlist.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 14:06:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 14:24:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fn				*create_rootlist(t_fn **array_nodes, size_t len)
{
	size_t			i;
	t_fn			*first;
	t_fn			*left;
	t_fn			*right;

	if (len < 1)
		return (NULL);
	i = 1;
	first = array_nodes[0];
	left = array_nodes[0];
	right = array_nodes[0];
	while (i < len)
	{
		if (array_nodes[i])
		{
			right = array_nodes[i];
			right->left = left;
			left->right = right;
			left = right;
		}
		i++;
	}
	right->left = first;
	first->right = right;
	return (first);
}
