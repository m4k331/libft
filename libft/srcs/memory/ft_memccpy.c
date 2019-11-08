/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:40:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/08 17:11:12 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	uint8_t		*pdst;
	uint8_t		*psrc;
	uint8_t		uc;

	if (dst == src)
		return (dst);
	uc = c;
	pdst = (uint8_t*)dst;
	psrc = (uint8_t*)src;
	while (n--)
	{
		if (*psrc == uc)
		{
			*pdst++ = *psrc;
			return (pdst);
		}
		*pdst++ = *psrc++;
	}
	return (NULL);
}
