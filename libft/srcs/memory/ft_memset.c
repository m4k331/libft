/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:04:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/08 17:03:35 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memset(void *b, int c, size_t len)
{
	uint64_t	*big;
	uint64_t	w;
	uint8_t		*small;
	uint8_t		s;

	big = b;
	w = (unsigned char)c;
	w |= w << 8ULL;
	w |= w << 16ULL;
	w |= w << 32ULL;
	while (len > 7ULL)
	{
		*big++ = w;
		len -= 8ULL;
	}
	s = w;
	small = (uint8_t*)big;
	while (len--)
		*small++ = s;
	return (b);
}
