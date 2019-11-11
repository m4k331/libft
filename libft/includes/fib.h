/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:51:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 23:29:50 by ahugh            ###   ########.fr       */
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

t_fn				*fnnew(void *value);
void				fndel(t_fn **node, void del(void*));
t_fn				*unbind_node(t_fn *list);
t_fn				*create_rootlist(t_fn **array_nodes, size_t len);
void				insert_node_in_rootlist(t_fn *rootlist, t_fn *node);
void				insert_child_node(t_fn *parent, t_fn *child);

/*
** fibonacci heap:
**		*ptr on priority node and root list
**		number of nodes
**		potential fibonacci heap
**		higher priority contains a value to unset an element from a heap
**		*ptr on function compare
**		*ptr on function delete t_fn->value
**
**	Note:
**	function cmp(value_1, value_2) return TRUE if value_1 priority than value_2
*/

typedef struct		s_fib
{
	t_fn			*priority;
	size_t			n;
	size_t			pot;
	void			*higher;
	int				(*cmp)(void*, void*);
	void			(*del)(void*);
}					t_fib;

t_fib				*ft_fibnew(int (*cmp)(void*, void*), void (*del)(void*), \
																void *higher);
t_fn				*ft_fibpop(t_fib *fib);
int					ft_fibset(t_fib *fib, void *value);
int					ft_fibupdval(t_fib *fib, t_fn *node, void *val);
int					ft_fibunset(t_fib *fib, t_fn **node);

#endif
