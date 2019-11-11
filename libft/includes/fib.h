/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:51:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 13:20:00 by ahugh            ###   ########.fr       */
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
	struct s_fn		*r;
	struct s_fn		*l;
	struct s_fn		*p;
	struct s_fn		*ch;
	void			*val;
	size_t			d;
	uint8_t			mark;
}					t_fn;

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
