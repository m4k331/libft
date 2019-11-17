/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_node_to_dictionary.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 15:34:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/14 15:31:32 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline int	add(t_vector *v, t_fn **n, char **k)
{
	ft_memdel((void**)k);
	if (ft_vpush_back(v, n, VOID_SIZE) == FALSE)
		return (FALSE);
	return (TRUE);
}

static inline int	set(t_fib *f, t_fn **n, char **k)
{
	t_vector		*v;

	v = ft_vnew(VOID_SIZE * DICT_MINSIZE, VOID_SIZE);
	if (v == NULL)
	{
		ft_memdel((void**)k);
		return (FALSE);
	}
	if (ft_dictset(f->values, *k, v) == FALSE)
	{
		ft_memdel((void**)k);
		ft_vdel(&v);
		return (FALSE);
	}
	if (ft_vpush_back(v, n, VOID_SIZE) == FALSE)
		return (FALSE);
	return (TRUE);
}

int 				add_node_to_dictionary(t_fib *fib, t_fn **node)
{
	void			*vec_vals;
	char			*k;

	k = ft_itoa_base((uint64_t)(*node)->value, 16);
//	printf("%p -> %ld\n", *node, *(long*)(*node)->value);
	if (k == NULL)
		return (FALSE);
	vec_vals = ft_dictget(fib->values, k);
	return (vec_vals == NULL ? set(fib, node, &k) : add(vec_vals, node, &k));
}
