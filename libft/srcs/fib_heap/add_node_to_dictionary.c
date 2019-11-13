/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:34:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 21:43:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	add(t_vector **v, t_fn *n, char **k)
{
	ft_memdel((void**)k);
	if (ft_vpush_back(*v, &n, VOID_SIZE) == FALSE)
		return (FALSE);
	return (TRUE);
}

static inline int	set(t_fib *f, t_fn *n, char **k)
{
	t_vector		**v;

	v = (t_vector**)malloc(VOID_SIZE);
	*v = ft_vnew(VOID_SIZE * 4, VOID_SIZE);
	if (*v == NULL)
	{
		ft_memdel((void**)k);
		return (FALSE);
	}
	if (ft_dictset(f->values, *k, v) == FALSE)
	{
		ft_memdel((void**)k);
		ft_vdel(v);
		return (FALSE);
	}
	if (ft_vpush_back(*v, &n, VOID_SIZE) == FALSE)
		return (FALSE);
	return (TRUE);
}

int 				add_node_to_dictionary(t_fib *fib, t_fn *node)
{
	void			*vvals;
	char			*k;

	k = ft_itoa_base((uint64_t)node->value, 16);
	if (k == NULL)
		return (FALSE);
	vvals = ft_dictget(fib->values, k);
	return (vvals == NULL ? set(fib, node, &k) : add((t_vector**)vvals, node, &k));
}
