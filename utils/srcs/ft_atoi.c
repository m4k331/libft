/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:54:58 by ahugh             #+#    #+#             */
/*   Updated: 2020/02/06 18:31:01 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define POS 0x7FFFFFFF
#define NEG 0x80000000

int				ft_atoi(const char *str)
{
	const long	atol = ft_atol(str);

	if ((atol < 0 && atol > NEG) || (atol > -1 && atol > POS))
		return (0);
	return (atol);
}
