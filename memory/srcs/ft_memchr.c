/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:24:58 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 00:59:15 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

inline uint64_t		any_zeroes(uint64_t value)
{
	return (value - 0x0101010101010101) & ~value & 0x8080808080808080;
}

static inline void	expand_value(uint64_t *w, uint8_t u)
{
	*w = u;
	*w |= *w << 8ULL;
	*w |= *w << 16ULL;
	*w |= *w << 32ULL;
}

void				*ft_memchr(const void *s, int c, size_t n)
{
	uint64_t		*longword;
	uint8_t			*byte;
	uint64_t		w;
	uint8_t			u;

	u = (unsigned char)c;
	expand_value(&w, u);
	longword = (uint64_t*)s;
	while (n > 7ULL)
	{
		if (any_zeroes(*longword) | any_zeroes(*longword ^ w))
			break ;
		longword++;
		n -= 8ULL;
	}
	byte = (uint8_t*)longword;
	while (n--)
		if (*byte == u)
			return (byte);
		else
			byte++;
	return (NULL);
}
