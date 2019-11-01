/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:18:22 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:18:22 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t				ft_dlstsize(t_dlist *dlst)
{
	size_t			count;

	count = 0;
	while (dlst)
	{
		dlst = dlst->next;
		count++;
	}
	return (count);
}
