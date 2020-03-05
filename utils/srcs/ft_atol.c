/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 19:03:10 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/19 20:51:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define POS 0x7FFFFFFFFFFFFFFF
#define NEG 0x8000000000000000

long			ft_atol(const char *str)
{
	uint64_t	res;
	uint8_t		len;
	int8_t		sgn;

	res = 0;
	len = 0;
	while (ft_isspace(*str))
		str++;
	sgn = (!ft_isdigit(*str) && *str == '-' ? -1 : 1);
	str += (*str == '+' || *str == '-' ? 1 : 0);
	while (*str == '0')
		str++;
	while (ft_isdigit(*str))
	{
		res = res * 10 + (*str - '0');
		str++;
		len++;
	}
	while (ft_isspace(*str))
		str++;
	if (len > 19 || \
		(len == 19 && ((sgn == -1 && res > NEG) || (sgn == 1 && res > POS))) \
															|| *str != '\0')
		return (0);
	return ((long)sgn * (long)res);
}
