/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 14:52:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 09:19:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			*ft_memmove(void *dst, const void *src, size_t len)
{
	uint8_t		*pdst;
	uint8_t		*psrc;

	if (dst == src)
		return (dst);
	if (src < dst)
	{
		pdst = (uint8_t*)dst;
		psrc = (uint8_t*)src;
		while (len--)
			pdst[len] = psrc[len];
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
