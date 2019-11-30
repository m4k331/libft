/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 20:49:35 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 20:39:49 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	swap64(uint64_t *long_a, uint64_t *long_b, size_t n)
{
	uint64_t		tmp;

	while (n)
	{
		tmp = *long_a;
		*long_a = *long_b;
		*long_b = tmp;
		long_a++;
		long_b++;
		n--;
	}
}

static inline void	swap8(uint8_t *byte_a, uint8_t *byte_b, size_t n)
{
	uint8_t		tmp;

	while (n)
	{
		tmp = *byte_a;
		*byte_a = *byte_b;
		*byte_b = tmp;
		byte_a++;
		byte_b++;
		n--;
	}
}

void				ft_memswap(void **a, void **b, size_t n)
{
	size_t			oct;

	if (a == NULL || b == NULL || n == 0)
		return ;
	oct = n / 8;
	swap64(*a, *b, oct);
	swap8(((*a) + oct), ((*b) + oct), n % 8);
}
