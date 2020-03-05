/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdellast.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/04 10:55:28 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 16:46:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdellast(t_list **alst, void (*del)(void*, size_t))
{
	t_list			*last;

	if (*alst == NULL || del == NULL)
		return ;
	last = ft_lstlast(*alst);
	ft_lstdelone(&last, del);
}
