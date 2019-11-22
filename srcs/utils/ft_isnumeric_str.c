/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumeric_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/19 21:12:56 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/23 00:22:50 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_isnumeric_str(const char *str, int is_spaces)
{
	char	*s;
	int8_t	empty;

	s = (char*)str;
	if (is_spaces == TRUE)
		while (ft_isspace(*s))
			s++;
	empty = ft_isdigit(*s) ? FALSE : TRUE;
	while (ft_isdigit(*s))
		s++;
	if (is_spaces == TRUE)
		while (ft_isspace(*s))
			s++;
	return (*s == '\0' && !empty);
}
