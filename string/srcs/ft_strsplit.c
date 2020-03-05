/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 16:05:21 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/28 18:56:44 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	size_t		i;
	size_t		wc;
	size_t		len;
	char		**result;

	result = NULL;
	wc = ft_wc(s, c);
	if (!(i = 0) && s)
		if ((result = (char**)malloc(sizeof(char*) * ++wc)))
			while (!(result[i] = 0) && --wc)
			{
				len = 0;
				while (*s == c && *s)
					s++;
				while (*s != c && *s && ++len)
					s++;
				if ((result[i] = ft_strnew(len)))
					ft_strncpy(result[i++], s - len, len);
				else
				{
					del_any_matrix((void**)result, 2);
					return (NULL);
				}
			}
	return (result);
}
