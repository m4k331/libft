/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:58 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/19 16:44:31 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memchr(const void *s, int c, size_t n)
{
	uint64_t	*big;
	uint64_t	ull;
	uint8_t		*small;
	uint8_t		uc;

	ull = (unsigned char)c;
	ull |= ull << 8ULL | ull << 16ULL | ull << 24ULL | ull << 32ULL;
	ull |= ull << 32ULL;
	uc = ull;
	big = (uint64_t*)s;
	while (n > 7ULL)
	{
		if (DETECTCHAR(*big, ull))
			break ;
		big++;
		n -= 8ULL;
	}
	small = (uint8_t*)big;
	while (n--)
	{
		if (*small == uc)
			return (small);
		small++;
	}
	return (NULL);
}
