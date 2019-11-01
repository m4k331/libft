/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_any_matrix.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 18:54:34 by ahugh             #+#    #+#             */
/*   Updated: 2019/08/02 14:51:13 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		del_any_matrix(void **matrix, int dimension)
{
	int		iter;

	iter = 0;
	if (dimension > 1)
	{
		if (dimension == 2)
		{
			while (matrix[iter])
			{
				ft_memdel((void **)&(matrix[iter]));
				iter++;
			}
		}
		else
		{
			while (matrix[iter])
			{
				del_any_matrix(matrix[iter], dimension - 1);
				iter++;
			}
		}
	}
	ft_memdel((void **)&matrix);
}
