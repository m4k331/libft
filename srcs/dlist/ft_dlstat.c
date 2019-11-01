/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:03:43 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:04:27 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstat(t_dlist *dlst, size_t nbr)
{
	size_t			iter;

	iter = 0;
	while (iter < nbr)
	{
		if (dlst == NULL)
			break ;
		dlst = dlst->next;
		iter++;
	}
	return (dlst);
}
