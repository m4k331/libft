/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 13:00:40 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 13:09:22 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_dlist				*ft_dlstnew(void const *con, size_t con_sz)
{
	t_dlist			*dlst;
	void			*dcon;

	dlst = (t_dlist *)malloc(sizeof(t_dlist));
	if (dlst == NULL)
		return (NULL);
	dcon = (void *)malloc(con_sz);
	if (dcon == NULL)
	{
		ft_memdel((void **)&dlst);
		return (NULL);
	}
	ft_memcpy(dcon, con, con_sz);
	dlst->con = dcon;
	dlst->con_sz = con_sz;
	dlst->next = NULL;
	dlst->prev = NULL;
	return (dlst);
}
