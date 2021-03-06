/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 23:34:05 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 04:08:09 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putchar(char c)
{
	int				w;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc < 128)
		w = write(STDOUT_FILENO, &c, 1);
	else
	{
		uc = (unsigned char)c >> 6 | 0xC0;
		w = write(STDOUT_FILENO, &uc, 1);
		uc = ((unsigned char)c & 0x3F) | 0x80;
		w = write(STDOUT_FILENO, &uc, 1);
	}
	w++;
}
