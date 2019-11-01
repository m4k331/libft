/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/23 16:29:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/01 19:33:08 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_H
# define VECTOR_H
# define EXPAND 2

typedef struct		s_vector
{
	const void		*const_con;
	void			*con;
	size_t			head;
	size_t			type_size;
	size_t			size;
}					t_vector;

t_vector			*ft_vnew(size_t v_size, size_t type_size);
size_t				ft_vmax_size(t_vector *v);
size_t				ft_vsize(t_vector *v);
size_t				ft_vunused_size(t_vector *v);
size_t				ft_vcapacity(t_vector *v);
void				*ft_vat(t_vector *v, size_t position);
void				ft_verase(t_vector *v);
void				*ft_vpop_back(t_vector *v);
void				ft_vdel(t_vector **v);
void				ft_vreserve(t_vector *v, size_t count);
int					ft_vresize(t_vector *v, size_t v_size);
int					ft_vpush_back(t_vector *v, void *val, size_t val_size);
int					ft_vreadfile(t_vector *v, int fd, size_t buff_size);

#endif