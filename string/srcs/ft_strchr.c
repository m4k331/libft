/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:29:51 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/20 00:54:20 by ahugh            ###   ########.fr       */
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

char				*ft_strchr(const char *s, int c)
{
	uint64_t		*longword;
	uint8_t			*byte;
	uint64_t		w;
	uint8_t			u;

	u = (unsigned char)c;
	expand_value(&w, u);
	byte = (uint8_t*)s;
	while ((uint64_t)byte & 7ULL)
	{
		if (*byte == '\0')
			return (NULL);
		if (*byte == u)
			return ((char*)byte);
		byte++;
	}
	longword = (uint64_t*)byte;
	while (any_zeroes(*longword) == 0 && \
					(any_zeroes(*longword) | any_zeroes(*longword ^ w)) == 0)
		longword++;
	byte = (uint8_t*)longword;
	if (any_zeroes(*longword) | any_zeroes(*longword ^ w))
		while (*byte && *byte != u)
			byte++;
	return (*byte == u ? (char*)byte : NULL);
}
