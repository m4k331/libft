/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrnew.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 20:37:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 20:37:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str				*ft_tstrnew(char *con, size_t len)
{
	t_str			*str;

	str = (t_str*)malloc(sizeof(t_str));
	if (str == NULL)
		return (NULL);
	str->con = (char*)malloc(len + 1);
	if (str->con == NULL)
	{
		ft_memdel((void**)&str);
		return (NULL);
	}
	ft_memcpy(str->con, con, len + 1);
	str->len = len;
	return (str);
}
