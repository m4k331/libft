/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delcontent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/03 15:52:31 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/03 15:52:31 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_delcontent(void *content, size_t content_size)
{
	if (content && content_size)
		ft_memdel((void **)&content);
	content_size = 0;
}
