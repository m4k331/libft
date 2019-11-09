/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlist.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 12:40:44 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:41:48 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLIST_H
# define DLIST_H
# include "libft.h"

typedef struct		s_dlist
{
	void			*con;
	size_t			con_sz;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}					t_dlist;

t_dlist				*ft_dlstnew(void const *con, size_t con_sz);
t_dlist				*ft_dlstmap(t_dlist *dlst, t_dlist *(*f)(t_dlist*));
t_dlist				*ft_dlstjoin(t_dlist *adlst, t_dlist *bdlst);
t_dlist				*ft_dlstat(t_dlist *dlst, size_t nbr);
t_dlist				*ft_dlstlast(t_dlist *dlst);
t_dlist				*ft_dlsthead(t_dlist *dlst);
t_dlist				*ft_dlstcreate(size_t size);
t_dlist				*ft_dlstcopy(t_dlist *dlst);
size_t				ft_dlstsize(t_dlist *dlst);
void				ft_dlstrev(t_dlist **dlst);
void				ft_dlstdelone(t_dlist **dlst, void (*del)(void*, size_t));
void				ft_dlstdel(t_dlist **dlst, void (*del)(void*, size_t));
void				ft_dlstadd(t_dlist **dlst, t_dlist *new);
void				ft_dlstiter(t_dlist *dlst, void (*f)(t_dlist*));
void				ft_dlstaddlast(t_dlist **dlst, t_dlist *new);
void				ft_dlstdellast(t_dlist **dlst, void (*del)(void*, size_t));
void				ft_dlstdelnbr(t_dlist **dlst, void (*del)(void*, size_t), \
																	size_t n);

#endif
