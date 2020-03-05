/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/05 17:33:08 by ahugh             #+#    #+#             */
/*   Updated: 2019/12/05 17:38:10 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_numlen(int64_t number, int base)
{
	const int64_t	threshold = base - 1;
	int				len;

	len = 1;
	while (number > threshold)
	{
		number /= base;
		len++;
	}
	return (len);
}
