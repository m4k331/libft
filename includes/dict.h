/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:36:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 13:52:39 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# define DICT_MINSIZE 8
# define PERTURB_SHIFT 5

typedef struct		s_slot
{
	unsigned long	ix;
	unsigned long	hash;
	char			*key;
	void			*value;
}					t_slot;

typedef struct		s_dict
{
	long			fill;
	long			used;
	long			mask;
	t_slot			*table;
	t_vector		*keys;
	t_vector		*items;
}					t_dict;

#endif
