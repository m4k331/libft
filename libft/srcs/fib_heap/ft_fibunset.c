/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibunset.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 23:17:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 23:22:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_fibunset(t_fib *fib, t_fn **node)
{
	if (ft_fibupdval(fib, *node, fib->higher) == FALSE)
		return (FALSE);
	ft_fibpop(fib);
	fib->del((*node)->value);
	ft_memdel((void**)node);
	return (TRUE);
}
