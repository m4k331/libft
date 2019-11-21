/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 17:49:41 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/20 01:14:25 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_strrchr(const char *s, int c)
{
	char		*prev;
	char		*next;

	prev = ft_strchr(s, c);
	next = prev;
	while (next)
	{
		prev = next;
		next = ft_strchr(prev + 1, c);
	}
	return (prev);
}
