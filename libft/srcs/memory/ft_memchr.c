/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:58 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/08 21:46:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

#define DETECTNULL(X) (((X) - 0x0101010101010101) & ~(X) & 0x8080808080808080)
#define DETECTCHAR(X, MASK) (DETECTNULL((X) ^ (MASK)))

void				*ft_memchr(const void *s, int c, size_t n)
{
	uint64_t		*big;
	uint64_t		ull;
	uint8_t			*small;
	uint8_t			uc;

	ull = (unsigned char)c;
	ull |= ull << 8ULL;
	ull |= ull << 16ULL;
	ull |= ull << 32ULL;
	big = (uint64_t*)s;
	while (n > 7ULL)
	{
		if (DETECTCHAR(*big, ull))
			break ;
		big++;
		n -= 8ULL;
	}
	uc = ull;
	small = (uint8_t*)big;
	while (n--)
	{
		if (*small == uc)
			return (small);
		small++;
	}
	return (NULL);
}
