/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:51:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 14:06:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIB_H
# define FIB_H

/*
** fibonacci node:
**		*ptr on right neighbor
**		*ptr on left neighbor
**		*ptr on parent node
**		*ptr on child node
**		*ptr on value
**		degree of child nodes
**		bool flag mark
*/

typedef struct		s_fn
{
	struct s_fn		*right;
	struct s_fn		*left;
	struct s_fn		*parent;
	struct s_fn		*child;
	void			*value;
	size_t			degree;
	uint8_t			mark;
}					t_fn;

t_fn				*create_rootlist(t_fn **array_nodes, size_t len);

/*
** fibonacci heap:
**		*ptr on minimum node and root list
**		number of nodes
**		potential fibonacci heap
*/

typedef struct		s_fib
{
	t_fn			*min;
	size_t			n;
	size_t			pot;
}					t_fib;

t_fib				*ft_fibnew(void);

#endif
