/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:07:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 16:16:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fn				*fnnew(void *value)
{
	t_fn			*node;

	node = (t_fn*)malloc(sizeof(t_fn));
	if (node == NULL)
		return (NULL);
	node->left = NULL;
	node->right = NULL;
	node->parent = NULL;
	node->child = NULL;
	node->value = value;
	node->degree = 0;
	node->mark = FALSE;
	return (node);
}
