/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:02:02 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 04:08:09 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_putchar_fd(char c, int fd)
{
	int				w;
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc < 128)
		w = write(fd, &c, 1);
	else
	{
		uc = (unsigned char)c >> 6 | 0xC0;
		w = write(fd, &uc, 1);
		uc = ((unsigned char)c & 0x3F) | 0x80;
		w = write(fd, &uc, 1);
	}
	w++;
}
