/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 20:36:02 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/27 21:12:30 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlen(const char *s)
{
	uint64_t	*longword;
	uint8_t		*byte;

	byte = (uint8_t*)s;
	while ((uint64_t)byte & 7ULL)
	{
		if (*byte == '\0')
			return ((size_t)byte - (size_t)s);
		byte++;
	}
	longword = (uint64_t*)byte;
	while (DETECTNULL(*longword) == FALSE)
		longword++;
	byte = (uint8_t*)longword;
	while (*byte)
		byte++;
	return ((size_t)byte - (size_t)s);
}
