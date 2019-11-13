/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/13 14:20:18 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/13 14:57:26 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline size_t	get_string_base_size(uint64_t num, uint64_t base)
{
	size_t				size;

	size = 1;
	while (num >= base)
	{
		num /= base;
		size++;
	}
	return (size);
}

char					*ft_itoa_base(uint64_t num, uint8_t base)
{
	const char			*digits = "0123456789ABCDEF";
	size_t				size;
	size_t				i;
	char				*string;

	if (base < 2 || base > 16)
		return (NULL);
	if (base == 10)
		return (ft_itoa((int)num));
	size = get_string_base_size(num, base);
	string = ft_strnew(size);
	i = 0;
	while (i < size)
	{
		string[size - i - 1] = digits[num % base];
		num /= base;
		i++;
	}
	return (string);
}
