/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tstr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <ahugh@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 18:59:52 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 21:05:01 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TSTR_H
# define TSTR_H

/*
** Structure for efficient string handling:
** con - *ptr on a sequence of characters
** len - number of characters in the string without terminating NULL character
*/
typedef struct		s_str
{
	char			*con;
	size_t			len;
}					t_str;

/*
** tstrbuild - the function converts a sequence of characters into
** 						a string t_str (without allocating memory for a string)
*/
t_str				*ft_tstrbuilt(char *con, size_t len);
/*
** tstrnew - the function create a new string t_str (with allocating memory)
*/
t_str				*ft_tstrnew(char *con, size_t len);
/*
** tstrdel - the function frees struct t_str memory
*/
void				ft_tstrdel(t_str **str);
/*
** tstrput - the function printing content on stdout
*/
void				ft_tstrput(t_str *str);
/*
** tstrputendl - the function printing content on stdout with '\n' in end line
*/
void				ft_tstrputendl(t_str *str);

#endif
