/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 16:11:13 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/21 01:50:34 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "libft.h"

# define BUFF_SIZE 1000
# define MIN_FD 0
# define MIN_BUFF_SIZE 0

# if BUFF_SIZE < 1024
#  define MIN_READ_BYTES (1024)
# endif

# if BUFF_SIZE > 1024
#  define MIN_READ_BYTES (BUFF_SIZE)
# endif

# define GNL_INIT_DICT_SIZE 16
# define GNL_INIT_VEC_SIZE ((MIN_READ_BYTES) * 2)

int					get_next_line(const int fd, char **line);

#endif
