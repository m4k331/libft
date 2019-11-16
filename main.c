/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 23:52:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/14 21:28:15 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static inline void	del_table(void **table, size_t len)
{
	size_t			iter;

	iter = 0;
	while (iter < len)
	{
		ft_memdel((void**)&table[iter]);
		iter++;
	}
}

char		**get_vals(char *prefix, size_t count, size_t size_vals)
{
	char	**keys;
	char	*num;
	size_t	offset;

	keys = (char**)malloc(sizeof(char*) * count);
	offset = ft_strlen(prefix);
	for (size_t i = 0; i < count; ++i)
	{
		keys[i] = ft_memalloc(size_vals);
		ft_memcpy(keys[i], prefix, offset);
		num = ft_itoa(i);
		ft_memcpy(keys[i] + offset, num, ft_strlen(num));
		free(num);
	}
	return (keys);
}

int			lambda(void *val)
{
	char	**str;

	str = val;
	((char*)*str)[0] = 'H';
	return (TRUE);
}

int			cmp(void *a, void *b)
{
	return (*(long*)a < *(long*)b ? TRUE : FALSE);
}

void			del(void *a)
{
	*(long*)a = 0;
}

int			main(int ac, char **av)
{
	t_fib	*fib;
	long	a = 100;
	long 	b = 60;
	long 	c = 90;
	long 	d = 10;
	long 	e = 8;
	long 	f = 77;
	long 	g = 13;
	long 	upd = 1;

	fib = ft_fibnew(cmp, del);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&a);
//	t_fn	*one_hundred = (t_fn*)fib->priority;
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&c);
	ft_fibpush(fib, (void*)&d);
//	ft_fibupd(fib, (void*)&a, (void*)&upd);
	ft_fibpush(fib, (void*)&f);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&a);
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&a);
	ft_fibpush(fib, (void*)&c);
	ft_fibpush(fib, (void*)&d);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&f);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&a);
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&f);
	ft_fibpush(fib, (void*)&f);
	ft_fibpush(fib, (void*)&f);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&a);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&g);
	ft_fibpush(fib, (void*)&e);
	ft_fibpush(fib, (void*)&g);
	for (int i = 0; fib->n; i++)
		printf("%d: %ld\n", i + 1, *(long*)ft_fibpop(fib));
	ft_fibdel(&fib);
	return (0);
}

//#define SZ 50000
//
//int			main(int ac, char **av)
//{
//	t_dict	*d;
//	void	**table;
//	char	**keys;
//	char	**lvls;
//	char	*fake = "FAKE";
//
//	d = ft_dictnew(0);
//
//	keys = get_vals("NAME_", SZ, DK_SIZE);
//	lvls = get_vals("AAA", SZ, DK_SIZE);
//
//	for (int i = 0; i < SZ; ++i)
//		ft_dictset(d, keys[i], &lvls[i]);
//
//	ft_dictiterate(d, lambda);
//	for (int j = 0; j < SZ; ++j)
//		printf("%10s %s\n", keys[j], *(char**)ft_dictget(d, keys[j]));
//
////	printf("unset: %s : %d\n", fake, ft_dictunset(d, fake, NULL));
////	printf("unset: %s : %d\n", keys[3], ft_dictunset(d, keys[3], NULL));
//	table = ft_dictkeys(d);
//	for (int k = 0; k < SZ; ++k)
//		printf(" %s ", table[k]);
//
//	del_table(table, SZ);
//	ft_memdel((void**)&table);
//
//	del_table((void**)keys, SZ);
//	ft_memdel((void**)&keys);
//
//	del_table((void**)lvls, SZ);
//	ft_memdel((void**)&lvls);
//
//	ft_dictdel(&d, NULL);
//	return (0);
//}