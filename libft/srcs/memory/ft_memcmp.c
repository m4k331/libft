/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:47:25 by ahugh             #+#    #+#             */
/*   Updated: 2018/11/30 19:36:06 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_memcmp(const void *s1, const void *s2, size_t n)
{
	uint8_t		*ps1;
	uint8_t		*ps2;

	ps1 = (uint8_t*)s1;
	ps2 = (uint8_t*)s2;
	while (n--)
		if (*ps1++ != *ps2++)
			return (*(--ps1) - *(--ps2));
	return (0);
}
