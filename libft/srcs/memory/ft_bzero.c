/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:26:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/19 17:25:38 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_bzero(void *s, size_t n)
{
	uint64_t	*longword;
	uint8_t		*byte;

	if (n < 0xFFF)
	{
		ft_memset(s, 0, n);
		return ;
	}
	byte = (uint8_t*)s;
	while ((uint64_t)byte & 7ULL)
	{
		*byte++ = 00U;
		if (--n == 0)
			return ;
	}
	longword = (uint64_t*)byte;
	while (n > 7ULL)
	{
		*longword++ = 0x0000000000000000ULL;
		n -= 8ULL;
	}
	byte = (uint8_t*)longword;
	while (n--)
		*byte++ = 00U;
}
