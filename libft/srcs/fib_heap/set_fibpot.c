/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_fibpot.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 18:51:11 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 18:57:43 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				set_fibpot(t_fib *fib)
{
	size_t			pot;
	size_t			shift;

	shift = 0;
	pot = 0;
	while (pot < fib->pot)
	{
		shift++;
		pot = fib->pot << shift;
	}
	fib->pot = shift;
}
