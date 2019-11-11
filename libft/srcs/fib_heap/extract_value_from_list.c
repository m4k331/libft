/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extract_value_from_list.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:21:48 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 17:50:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*extract_value_from_list(t_fn **node)
{
	void			*value;

	unbind_node(*node);
	value = (*node)->value;
	fndel(node, NULL);
	return (value);
}
