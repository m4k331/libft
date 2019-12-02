/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:29:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/12/02 17:21:04 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# define EXPAND 2

typedef struct		s_vector
{
	const void		*const_con;
	void			*con;
	long			head;
	long			iter;
	long			type_size;
	long			size;
}					t_vector;

t_vector			*ft_vnew(long bytes_size, long type_size);
t_vector			*ft_vcopy(t_vector *v);
void				*ft_vat(t_vector *v, long position);
void				*ft_vpop_back(t_vector *v);
void				*ft_vpop_at(t_vector *v, long position);
void				*ft_vnext_con(t_vector *v);
void				*ft_vback_con(t_vector *v);
void				*ft_vcurr_con(t_vector *v);
void				ft_verase(t_vector *v);
void				ft_vdel(t_vector **v);
long				ft_vsize(t_vector *v);
long				ft_vunused_size(t_vector *v);
/*
** ft_vmap - the function applies the subfunc map \
** starting from the iteration 'with_iterate' to each element of the vector \
** subfinc int map(void*) takes one value of the vector \
** and in case of success manipulation with it returns TRUE and otherwise FALSE
** returns: TRUE or FALSE depending on the success of applying the subfunc
*/
int					ft_vmap(t_vector *v, long with_iterate, int (*map)(void*));
int					ft_vreserve(t_vector *v, long count);
int					ft_vreader(t_vector *v, int fd, int buff_size);
int					ft_vresize(t_vector *v, long v_size);
int					ft_vpush_back(t_vector *v, void *val, long val_size);

#endif
