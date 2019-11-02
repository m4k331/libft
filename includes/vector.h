/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:29:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/02 15:54:37 by ahugh            ###   ########.fr       */
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

t_vector			*ft_vnew(long v_size, long type_size);
void				*ft_vat(t_vector *v, long position);
void				*ft_vpop_back(t_vector *v);
void				*ft_vnext_con(t_vector *v);
void				*ft_vback_con(t_vector *v);
void				*ft_vcurr_con(t_vector *v);
void				ft_verase(t_vector *v);
void				ft_vdel(t_vector **v);
long				ft_vsize(t_vector *v);
long				ft_vunused_size(t_vector *v);
int					ft_vreserve(t_vector *v, long count);
int					ft_vresize(t_vector *v, long v_size);
int					ft_vpush_back(t_vector *v, void *val, long val_size);

#endif
