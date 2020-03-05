/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   duplicate_key.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/30 03:34:03 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/30 03:34:19 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int8_t			duplicate_key(char **dup_key, char *key)
{
	*dup_key = (char*)malloc((DK_SIZE + 1) * sizeof(char));
	if (*dup_key == NULL)
		return (FALSE);
	ft_memccpy(*dup_key, key, 0, DK_SIZE);
	(*dup_key)[DK_SIZE] = 0;
	return (TRUE);
}
