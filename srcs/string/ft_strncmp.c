/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:43:54 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/28 20:27:24 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_strncmp(const char *s1, const char *s2, size_t n)
{
	uint8_t		*ps1;
	uint8_t		*ps2;

	if (n == 0 || s1 == s2)
		return (0);
	if (s1 == NULL)
		return (-*s2);
	if (s2 == NULL)
		return (*s1);
	ps1 = (uint8_t*)s1;
	ps2 = (uint8_t*)s2;
	while (--n && *ps1 && *ps2 && *ps1 == *ps2)
	{
		ps1++;
		ps2++;
	}
	return (*ps1 - *ps2);
}
