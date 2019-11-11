/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:13:52 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 19:04:33 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_fibpop(t_fib *fib)
{
	t_fn			*priority;
	t_fn			**roots;
	void			*value;

	if (fib->priority == NULL)
		return (NULL);
	set_fibpot(fib);
	roots = (t_fn**)ft_memalloc(sizeof(t_fn*) * fib->pot);
	if (roots == NULL)
		return (NULL);
	priority = fib->priority;
	if (priority->right == priority)
	{
		fib->priority = NULL;
		value = extract_value_from_list(&priority);
	}
	else
	{
		fib->priority = priority->right;
		value = extract_value_from_list(&priority);
		consolidate(fib, roots);
	}
	fib->n--;
	return (value);
}
