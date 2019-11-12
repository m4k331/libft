/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:49:30 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 23:24:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fib				*ft_fibnew(int (*cmp)(void*, void*), void (*del)(void*), \
																void *higher)
{
	t_fib			*fib;

	fib = (t_fib*)ft_memalloc(sizeof(fib));
	if (fib == NULL)
		return (NULL);
	fib->higher = higher;
	fib->cmp = cmp;
	fib->del = del;
	return (fib);
}
