/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fstrbuilt.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:59:27 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 20:20:56 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_str				*ft_tstrbuilt(char *con, size_t len)
{
	t_str			*str;

	str = (t_str*)malloc(sizeof(t_str));
	if (str == NULL)
		return (NULL);
	str->con = con;
	str->len = len;
	return (str);
}
