/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fib.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 12:51:37 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 17:12:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIB_H
# define FIB_H

# define DICT_SIZE 16

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
t_fn				*create_rootlist(t_fn **nodes, size_t len);
void				insert_node_in_rootlist(t_fn *rootlist, t_fn *node);
void				insert_child_node(t_fn *parent, t_fn *child);

/*
** fibonacci heap:
**		*ptr on priority node and root list
**		number of nodes
**		potential fibonacci heap
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
	t_dict			*values;
	int				(*cmp)(void*, void*);
	void			(*del)(void*);
}					t_fib;

void				*extract_priority_value(t_fib *fib);
int 				add_node_to_dictionary(t_fib *fib, t_fn **node);
int 				del_node_from_dictionary(t_fib *fib, t_fn *req_node);

t_fib				*ft_fibnew(int (*cmp)(void*, void*), void (*del)(void*));
void				*ft_fibpop(t_fib *fib);
int					ft_fibpush(t_fib *fib, void *value);
void				*ft_fibupd(t_fib *fib, void *old_val, void *new_val);
void				ft_fibdel(t_fib **fib);


#endif
