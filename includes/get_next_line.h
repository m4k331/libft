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

# define BUFF_SIZE 4096
# define FREE_FD -1
# define MIN_BUFF_SIZE 0

# if BUFF_SIZE < 1024
#  define MIN_READ_BYTES 1024
# endif

# if BUFF_SIZE > 1024
#  define MIN_READ_BYTES BUFF_SIZE
# endif

# define GNL_INIT_DICT_SIZE 16

int					get_next_line(const int fd, char **line);
int					del_entire_dict(t_dict **dict);

#endif
