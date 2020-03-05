/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrputendl_fd.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/09 02:13:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/12/09 02:14:23 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_tstrputendl_fd(int fd, t_str *str)
{
	int				w;

	str->con[str->len] = '\n';
	w = write(fd, str->con, str->len + 1);
	str->con[str->len] = '\0';
	w++;
}
