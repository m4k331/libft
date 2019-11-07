/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdellast.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 16:41:52 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:46:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_dlstdellast(t_dlist **dlst, void (*del)(void*, size_t))
{
	t_dlist			*last;

	if (*dlst == NULL || del == NULL)
		return ;
	last = ft_dlstlast(*dlst);
	ft_dlstdelone(&last, del);
}
