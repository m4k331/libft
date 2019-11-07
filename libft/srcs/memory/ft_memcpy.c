/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:37:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/07 07:13:39 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint64_t	*big_dst;
	uint64_t	*big_src;
	uint8_t		*small_dst;
	uint8_t		*small_src;

	if (dst == src)
		return (dst);
	big_src = (uint64_t*)src;
	big_dst = dst;
	while (n > 7ULL)
	{
		*big_dst++ = *big_src++;
		n -= 8ULL;
	}
	small_src = (uint8_t*)big_src;
	small_dst = (uint8_t*)big_dst;
	while (n--)
		*small_dst++ = *small_src++;
	return (dst);
}
