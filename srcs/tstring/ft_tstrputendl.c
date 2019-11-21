/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tstrputendl.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:03:03 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 21:03:05 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_tstrputendl(t_str *str)
{
	int				w;

	str->con[str->len] = '\n';
	w = write(STDOUT_FILENO, str->con, str->len + 1);
	str->con[str->len] = '\0';
	w++;
}