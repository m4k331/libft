/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unbind_node.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:45:00 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 17:50:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fn				*unbind_node(t_fn *list)
{
	t_fn			*node;
	t_fn			*right;
	t_fn			*left;

	node = list;
	right = node->right;
	left = node->left;
	left->right = right;
	right->left = left;
	return (node);
}
