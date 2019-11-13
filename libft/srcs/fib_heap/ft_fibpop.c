/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:13:52 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 13:24:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	set_fibpot(t_fib *fib)
{
	size_t			pot;
	size_t			shift;

	shift = 0;
	pot = 0;
	while (pot < fib->n)
	{
		shift++;
		pot = 1ULL << shift;
	}
	fib->pot = shift + 1;
}

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
		if (fib->cmp(bound->value, unbound->value) == TRUE)
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
	t_fn			*unbind;
	t_fn			*prior;
	t_fn			*last;

	prior = fib->priority;
	last = prior->left;
	while (TRUE)
	{
		next = fib->priority->right;
		if (fib->cmp(fib->priority->value, prior->value) == TRUE)
			prior = fib->priority;
		unbind = unbind_node(fib->priority);
		root_binding(fib, roots, unbind);
		if (fib->priority == last)
			break ;
		fib->priority = next;
	}
	fib->priority = prior;
	create_rootlist(roots, fib->pot);
}

t_fn				*ft_fibpop(t_fib *fib)
{
	t_fn			*prior;
	t_fn			**roots;

	if (fib->priority == NULL)
		return (NULL);
	set_fibpot(fib);
	roots = (t_fn**)ft_memalloc(sizeof(t_fn*) * fib->pot);
	if (roots == NULL)
		return (NULL);
	prior = extract_priority(fib);
	if (fib->priority)
		consolidate(fib, roots);
	ft_memdel((void**)&roots);
	fib->n--;
	return (prior);
}
