/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 20:38:55 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/05 21:03:57 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned long		ft_hash(char *key)
{
	unsigned long	hash;
	unsigned long	len;
	unsigned long	iter;

	len = ft_strlen(key);
	if (len > DK_SIZE)
		len = DK_SIZE;
	hash = ((unsigned long)*key) << 7ULL;
	iter = 0;
	while (iter < len)
	{
		hash = (1000003 * hash) ^ (unsigned long)key[iter];
		iter++;
	}
	return (hash ^ len);
}
