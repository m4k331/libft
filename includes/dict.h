/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dict.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 13:36:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/25 18:08:09 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DICT_H
# define DICT_H
# define DICT_MINSIZE 8ULL
# define DK_SIZE 16ULL
# define VOID_SIZE 8ULL
# define GROW_RATE(dict)   ((dict)->mask * 3ULL)
# define REDUCE_RATE(dict) ((dict)->used * 3ULL)
# define PERTURB_SHIFT 5ULL

# define MASK_ACTIVE  0x8000000000000000ULL
# define MASK_DUMMY   0x4000000000000000ULL
# define MASK_ERROR   0x2000000000000000ULL
# define MASK_INDICES 0x0FFFFFFFFFFFFFFFULL

# define DKIX_ACTIVE(ix) ((ix) & MASK_ACTIVE)
# define DKIX_DUMMY(ix)  ((ix) & MASK_DUMMY)
# define DKIX_ERROR(ix)  ((ix) & MASK_ERROR)
# define DKIX_EMPTY(ix)  ((ix) == 0)
# define DKIX(ix)        ((ix) & MASK_INDICES)

# define USABLE(n) (((n) << 1ULL) / 3ULL)

/*
** ix bit field which containing values indices slots and his flags
*/

typedef struct	s_slot
{
	size_t		ix;
	size_t		hash;
	char		*key;
	void		*value;
}				t_slot;

t_slot			**ft_slotsnew(size_t length);
void			ft_slotsdel(t_slot ***slots, void del(void*), size_t length);

typedef struct	s_dict
{
	size_t		mask;
	size_t		used;
	size_t		fill;
	t_slot		**table;
	t_vector	*keys;
	t_vector	*items;
}				t_dict;

t_dict			*ft_dictnew(size_t size);
char			**ft_dictkeys(t_dict *dict);
void			*ft_dictget(t_dict *dict, char *key);
void			ft_dictdel(t_dict **dict, void del(void*));
int				ft_dictunset(t_dict *dict, char *key, void del(void*));
int				ft_dictset(t_dict *dict, char *key, void *value);
int				ft_dictresize(t_dict *dict, int grow);
int				ft_dictiterate(t_dict *dict, int map(void*));
void			*ft_dictnext_item(t_dict *dict);
char			*ft_dictnext_key(t_dict *dict);

size_t			ft_hash(char *key);
t_slot			*ft_lookup(t_dict *d, size_t hash, char *key, int set);
void			insert_values_in_dict(t_dict *dict, char *key, void *value);

#endif
