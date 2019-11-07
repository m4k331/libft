/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 12:26:46 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/07 06:19:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_bzero(void *s, size_t n)
{
	size_t		count_big;
	size_t		count_small;
	uint64_t	*big;
	uint8_t		*small;

	count_big = n >> 3ULL;
	count_small = n - (count_big << 3ULL);
	small = s;
	while (count_small--)
		*small++ = 0;
	small--;
	big = (uint64_t*)small;
	while (count_big--)
		*big++ = 0ULL;
}
