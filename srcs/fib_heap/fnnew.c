/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fnnew.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:10:39 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/18 19:04:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fn				*fnnew(void *value)
{
	t_fn			*node;

	node = (t_fn*)ft_memalloc(sizeof(t_fn));
	if (node == NULL)
		return (NULL);
	node->value = value;
	return (node);
}
