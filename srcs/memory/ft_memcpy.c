/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:37:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/06 19:46:54 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	uint64_t	count_big;
	uint64_t	*big;
	uint8_t		count_small;
	uint8_t		*small;

	if (dst == src)
		return (dst);
	count_big = n / 8;
	count_small = n - count_big;
	big = dst;
	while (count_big--)
		*big++ = *(uint64_t*)src++;
	src--;
	small = (uint8_t*)src;
	while (count_small--)
		*small++ = *(uint8_t*)src++;
	return (dst);
}
