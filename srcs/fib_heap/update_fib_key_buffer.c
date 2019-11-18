/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_fib_key_buffer.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 22:20:53 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/18 19:04:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define SIZE_LINE (DICT_SIZE - 1)

void					update_fib_key_buffer(char *buffer, size_t address)
{
	const char			*digits = "0123456789ABCDEF";
	size_t				i;

	i = 0;
	while (i < SIZE_LINE)
	{
		buffer[SIZE_LINE - i - 1] = digits[address % 16];
		address /= 16;
		i++;
	}
}
