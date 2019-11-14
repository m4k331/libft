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

char		**getmems(char **tmp, size_t len, size_t size)
{
	char	**keys;

	keys = (char**)malloc(sizeof(char*) * len);
	for (int i = 0; i < len; ++i)
	{
		keys[i] = ft_memalloc(size);
		ft_memcpy(keys[i], tmp[i], size);
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
	long 	upd = 1;

	fib = ft_fibnew(cmp, del);
	ft_fibpush(fib, (void*)&a);
//	t_fn	*one_hundred = (t_fn*)fib->priority;
	ft_fibpush(fib, (void*)&b);
	ft_fibpush(fib, (void*)&c);
	ft_fibpush(fib, (void*)&d);
	ft_fibpush(fib, (void*)&e);
//	ft_fibupd(fib, one_hundred, (void*)&upd);
	ft_fibpush(fib, (void*)&f);
	for (int i = 0; fib->n; i++)
		printf("%d: %ld\n", i + 1, *(long*)ft_fibpop(fib));
	return (0);
}

//#define SZ 11
//
//int			main(int ac, char **av)
//{
//	char	*t_k[SZ] = {"ahugh", "chermist", "lkarlon-", "adavis", \
//					"mbalon-s", "ehugh-be", "mwunsch", "O1", "O2", "O3", "O4"};
//	char	*t_l[SZ] = {"7.90", "7.47", "7.62", "7.11", "7.56", "8.31", "8.72", \
//						"11", "22", "33", "44"};
//	t_dict	*d;
//	void	**table;
//	char	**keys;
//	char	**lvls;
//	char	*fake = "FAKE";
//
//	d = ft_dictnew(0);
//
//	keys = getmems(t_k, SZ, DK_SIZE);
//	lvls = getmems(t_l, SZ, sizeof(void*));
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