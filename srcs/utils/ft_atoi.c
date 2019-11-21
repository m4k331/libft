/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 14:54:58 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/19 20:52:21 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define POS(x) ((x) > 0x7FFFFFFF)
#define NEG(x) ((x) > 0x80000000)
#define OVER_LIMIT(x) (((x) < 0 && NEG((x))) || ((x) > -1 && POS((x))))

int				ft_atoi(const char *str)
{
	const long	atol = ft_atol(str);

	return (OVER_LIMIT(atol) ? 0 : (int)atol);
}
