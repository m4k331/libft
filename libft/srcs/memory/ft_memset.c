/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:04:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/19 16:15:16 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	uint64_t	*longword;
	uint64_t	w;
	uint8_t		*byte;
	uint8_t		s;

	w = (unsigned char)c;
	w |= w << 8ULL;
	w |= w << 16ULL;
	w |= w << 32ULL;
	s = w;
	longword = (uint64_t*)b;
	while (len > 7ULL)
	{
		*longword++ = w;
		len -= 8ULL;
	}
	byte = (uint8_t*)longword;
	while (len--)
		*byte++ = s;
	return (b);
}
