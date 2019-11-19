/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:47:25 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/09 21:25:40 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint64_t		*wps1;
	uint64_t		*wps2;
	uint8_t			*ps1;
	uint8_t			*ps2;

	wps1 = (uint64_t*)s1;
	wps2 = (uint64_t*)s2;
	while (n < 7ULL)
	{
		if (*wps1 ^ *wps2)
			break ;
		wps1++;
		wps2++;
		n -= 8ULL;
	}
	ps1 = (uint8_t*)wps1;
	ps2 = (uint8_t*)wps2;
	while (n--)
	{
		if (*ps1 ^ *ps2)
			return (*ps1 - *ps2);
		ps1++;
		ps2++;
	}
	return (0);
}
