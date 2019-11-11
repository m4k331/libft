/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:13:52 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 17:14:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_fibpop(t_fib *fib)
{
	t_fn			*priority;

	if (fib->priority == NULL)
		return (NULL);
	priority = fib->priority;

	return (priority->value);
}
