/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 11:04:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/07 17:43:03 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memset(void *b, int c, size_t len)
{
	uint64_t			*big;
	uint64_t			w;
	uint8_t				*small;
	uint8_t				s;

	big = (uint64_t*)b;
	w = c;
	w |= w << 8 | w << 16 | w << 24 | w << 32 | w << 40 | w << 48 | w << 56;
	while (len > 7ULL)
	{
		*big++ = w;
		len -= 8ULL;
	}
	s = c;
	small = (uint8_t*)big;
	while (len--)
		*small++ = s;
	return (b);
}
