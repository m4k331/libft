/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:36:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 23:27:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# define DICT_MINSIZE 8
# define DK_SIZE 16
# define GROW_RATE(d) ((d)->mask * 3)
# define PERTURB_SHIFT 5

# define DKIX_ACTIVE(ix) ((ix) & 0x80000000)
# define DKIX_DUMMY(ix)  ((ix) & 0x40000000)
# define DKIX_ERROR(ix)  ((ix) & 0x20000000)
# define DKIX_EMPTY(ix)  ((ix) == 0)
# define DKIX(ix)        ((ix) & 0x0FFFFFFF)

/*
** ix bit field which containing values indices slots and his flags
** ix & 0x0FFFFFFF containing indices
** ix & 0x80000000 active slot
** ix & 0x40000000 dummy slot
** ix & 0x20000000 error slot
** ix & 0x10000000 empty slot
*/

typedef struct		s_slot
{
	unsigned long	hash;
	char			*key;
	void			*value;
	unsigned int	ix;
}					t_slot;

t_slot				**ft_slotsnew(long length);
void				ft_slotsdel(t_slot ***slots, void del(void*), long length);

typedef struct		s_dict
{
	t_slot			**table;
	t_vector		*keys;
	t_vector		*items;
	unsigned long	mask;
	unsigned int	used;
	unsigned int	fill;
}					t_dict;

t_dict				*ft_dictnew(void);
void				ft_dictdel(t_dict **dict, void del(void*));
int					ft_dictset(t_dict *dict, char *key, void *value);

unsigned long		ft_hash(char *key);

#endif
