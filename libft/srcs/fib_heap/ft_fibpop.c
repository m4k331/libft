/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:13:52 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 21:17:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	fibheap_link(t_fn *bound, t_fn *unbound)
{
	insert_child_node(unbound, bound);
	bound->mark = FALSE;
}

static inline void	root_binding(t_fib *fib, t_fn **roots, t_fn *unbound)
{
	size_t			d;
	t_fn			*bound;

	d = unbound->degree;
	while (roots[d] != NULL)
	{
		bound = roots[d];
		if (fib->cmp(unbound, bound) == TRUE)
			ft_swap64((uint64_t*)&unbound, (uint64_t*)&bound);
		fibheap_link(bound, unbound);
		roots[d] = NULL;
		d++;
	}
	roots[d] = unbound;
}

static inline void	consolidate(t_fib *fib, t_fn **roots)
{
	t_fn			*next;
	t_fn			*root;
	t_fn			*prior;

	prior = fib->priority;
	while (fib->priority->right)
	{
		next = fib->priority->right;
		if (fib->cmp(fib->priority, prior) == TRUE)
			prior = fib->priority;
		root = unbind_node(fib->priority);
		fib->priority = next;
		root_binding(fib, roots, root);
	}
	fib->priority = prior;
	create_rootlist(roots, fib->pot);
}

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
		ft_memdel((void**)&roots);
	}
	fib->n--;
	return (value);
}
