/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibpop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 17:13:52 by ahugh             #+#    #+#             */
/*   Updated: 2020/02/06 20:00:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int		update_length_rootlist(t_fib *fib)
{
	size_t				pot;

	if (fib->n > (size_t)(1ULL << fib->pot))
	{
		fib->pot = 0;
		pot = 0;
		while (pot < fib->n)
			pot = 1ULL << fib->pot++;
		fib->pot++;
		if (fib->rootlist)
			ft_memdel((void**)&fib->rootlist);
		fib->rootlist = (t_fn**)ft_memalloc(sizeof(t_fn*) * fib->pot);
		if (fib->rootlist == NULL)
			return (FALSE);
	}
	return (TRUE);
}

static inline size_t	root_binding(t_fib *fib, t_fn *unbound)
{
	size_t				d;
	t_fn				*bound;

	d = unbound->degree;
	while (fib->rootlist[d] != NULL)
	{
		bound = fib->rootlist[d];
		if (fib->cmp(bound->value, unbound->value) == TRUE)
			ft_swap64((uint64_t*)&unbound, (uint64_t*)&bound);
		insert_child_node(unbound, bound);
		bound->mark = FALSE;
		fib->rootlist[d] = NULL;
		d++;
	}
	fib->rootlist[d] = unbound;
	return (d);
}

static inline void		create_rootlist(t_fib *fib, long idx)
{
	t_fn				*first;
	t_fn				*left;
	t_fn				*right;

	first = fib->rootlist[idx];
	left = fib->rootlist[idx];
	right = fib->rootlist[idx];
	fib->priority = fib->rootlist[idx];
	while (idx > -1)
	{
		if (fib->rootlist[idx])
		{
			if (fib->cmp(fib->rootlist[idx]->value, fib->priority->value))
				fib->priority = fib->rootlist[idx];
			right = fib->rootlist[idx];
			right->left = left;
			left->right = right;
			left = right;
			fib->rootlist[idx] = NULL;
		}
		idx--;
	}
	right->right = first;
	first->left = right;
}

static inline void		consolidate(t_fib *fib)
{
	t_fn				*next;
	t_fn				*unbind;
	t_fn				*last;
	size_t				idx;
	size_t				last_idx;

	last_idx = 0;
	last = fib->priority->left;
	while (TRUE)
	{
		next = fib->priority->right;
		unbind = unbind_node(fib->priority);
		idx = root_binding(fib, unbind);
		if (idx > last_idx)
			last_idx = idx;
		if (fib->priority == last)
			break ;
		fib->priority = next;
	}
	create_rootlist(fib, last_idx);
}

void					*ft_fibpop(t_fib *fib)
{
	void				*priority_value;

	if (fib->priority == NULL)
		return (NULL);
	if (update_length_rootlist(fib) == FALSE)
		return (NULL);
	priority_value = extract_priority_value(fib);
	if (fib->priority)
		consolidate(fib);
	fib->n--;
	return (priority_value);
}
