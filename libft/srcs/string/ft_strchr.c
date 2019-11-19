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
	while (DETECTNULL(*longword) == FALSE && DETECTCHAR(*longword, w) == FALSE)
		longword++;
	byte = (uint8_t*)longword;
	if (DETECTCHAR(*longword, w))
		while (*byte && *byte != u)
			byte++;
	return (*byte == u ? (char*)byte : NULL);
}
