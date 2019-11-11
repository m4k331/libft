/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:15:15 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 17:21:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_fibset(t_fib *fib, void *value)
{
	t_fn			*node;

	node = fnnew(value);
	if (node == NULL)
		return (FALSE);
	if (fib->priority == NULL)
		fib->priority = create_rootlist(&node, 1);
	else
	{
		insert_node_in_rootlist(fib->priority, node);
		if (fib->cmp(fib->priority->value, node->value) == FALSE)
			fib->priority = node;
	}
	fib->n++;
	return (TRUE);
}
