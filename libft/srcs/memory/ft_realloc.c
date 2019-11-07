/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: djon-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/09 04:24:23 by djon-con          #+#    #+#             */
/*   Updated: 2018/12/09 04:44:40 by djon-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_realloc(void *ptr, size_t size)
{
	void	*tmp;

	tmp = ft_strnew(size);
	if (tmp == NULL)
		return (ptr);
	ft_memmove(tmp, ptr, size);
	ft_memdel((void**)&ptr);
	return (tmp);
}
