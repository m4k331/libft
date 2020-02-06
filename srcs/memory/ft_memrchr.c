/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 16:26:59 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 17:01:12 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	set_values(uint64_t *w, uint8_t *u, int c)
{
	*u = (unsigned char)c;
	*w = *u;
	*w |= *w << 8ULL;
	*w |= *w << 16ULL;
	*w |= *w << 32ULL;
}

static inline void	*longword_research(uint64_t *longword, uint8_t u)
{
	uint8_t			*byte;
	uint8_t			len;

	len = 8;
	byte = (uint8_t*)longword + 8;
	while (len--)
	{
		if (*byte == u)
			break ;
		byte--;
	}
	return (byte);
}

void				*ft_memrchr(const void *s, int c, size_t n)
{
	uint64_t		*longword;
	uint8_t			*byte;
	uint64_t		w;
	uint8_t			u;

	set_values(&w, &u, c);
	longword = (uint64_t*)((uint8_t*)s + n);
	while (n > 7ULL)
	{
		longword--;
		if (((((*longword) - M1) & ~(*longword) & M2) ^ w))
			return (longword_research(longword, u));
		n -= 8ULL;
	}
	byte = (uint8_t*)longword - 1;
	while (n--)
	{
		if (*byte == u)
			return (byte);
		byte--;
	}
	return (NULL);
}
