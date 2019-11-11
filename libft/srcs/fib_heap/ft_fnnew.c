/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fnnew.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/11 16:07:45 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/11 16:07:45 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_fn				*ft_fnnew(void *value)
{
	t_fn			*fn;

	fn = (t_fn*)malloc(sizeof(t_fn));
	if (fn == NULL)
		return (NULL);
	fn->left = NULL;
	fn->right = NULL;
	fn->parent = NULL;
	fn->child = NULL;
	fn->value = value;
	fn->degree = 0;
	fn->mark = FALSE;
	return (fn);
}
