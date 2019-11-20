/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:39:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/20 18:33:18 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Vector structure used in GNL:
** ............................................................................
** data->const_con - *ptr to the beginning of the vector
** data->con - *ptr to the current starting position of the data in the vector
** data->head - number of bytes from CONST_CON to the end of the read data
** data->iter - number of examined bytes for the presence of '\n' from the
** 						beginning of the vector to the last investigated byte
** data->type_size - size of data units in bytes
** data->size - memory size of the whole vector
*/

static int			initialize_elements(int fd, \
										char **line, \
										t_dict **dict, \
										t_vector **data)
{
	char			*key;
	int				dkix;

	*line = NULL;
	dkix = TRUE;
	*dict = (*dict == NULL ? ft_dictnew(GNL_INIT_DICT_SIZE) : *dict);
	if (*dict == NULL)
		return (FALSE);
	key = ft_itoa_base(fd, 16);
	*data = ft_dictget(*dict, key);
	if (*data == NULL)
	{
		*data = ft_vnew(GNL_INIT_VEC_SIZE, sizeof(char));
		if (*data == NULL || ft_dictset(*dict, key, *data) == FALSE)
			dkix = FALSE;
		else
			(*data)->iter = 0;
	}
	ft_memdel((void**)&key);
	return (dkix);
}

static size_t		set_data_inline(t_vector *data, char **line)
{
	size_t			dkix;
	char			*ptr_nl;
	char			*begin;
	char			*end;

	begin = ((char*)data->const_con) + data->iter;
	end = ((char*)data->const_con) + data->head;
	if ((long)begin >= (long)end)
		return (0);
	ptr_nl = (char*)ft_memchr(begin, '\n', data->head - (long)begin);
	data->iter = ptr_nl ? (long)ptr_nl - (long)data->const_con + 1 : data->head;
	if (ptr_nl == NULL)
		return (0);
	dkix = (size_t)ptr_nl - (size_t)data->con;
	*line = ft_strnew(dkix);
	if (*line)
	{
		ft_memcpy(*line, data->con, dkix);
		data->con += dkix + 1;
	}
	dkix |= (*line == NULL ? MASK_ERROR : MASK_ACTIVE);
	return (dkix);
}

static int			read_data(int fd, t_vector *data)
{
	int				read_bytes;
	int				state;

	if ((data->size - data->head) < MIN_READ_BYTES)
	{
		data->head -= ((long)data->con - (long)data->const_con);
		data->iter -= ((long)data->con - (long)data->const_con);
		ft_memmove((void*)data->const_con, data->con, data->head);
		if (ft_vresize(data, (data->size + MIN_READ_BYTES) * 2) == FALSE)
			return (-1);
	}
	read_bytes = 0;
	while (MIN_READ_BYTES > read_bytes)
	{
		state = read(fd, data->con + read_bytes, BUFF_SIZE);
		if (state == 0)
		{
			((char*)data->const_con)[data->head] = '\n';
			read_bytes = (int)(data->con - data->head);
			break ;
		}
		if (state == -1)
			return (-1);
		read_bytes += state;
		data->head += read_bytes;
	}
	return (read_bytes);
}

static int			del_data_indict(int fd, \
									t_dict *dict, \
									t_vector **data)
{
	char			*key;
	int				state_unset_dictionary;

	key = ft_itoa_base(fd, 16);
	if (key == NULL)
		return (FALSE);
	ft_vdel(data);
	state_unset_dictionary = ft_dictunset(dict, key, NULL);
	ft_memdel((void**)&key);
	return (state_unset_dictionary);
}

int					get_next_line(const int fd, char **line)
{
	static t_dict	*dict = NULL;
	t_vector		*data;
	size_t			dkix;
	int				read_bytes;

	if (fd < MIN_FD || BUFF_SIZE < MIN_BUFF_SIZE || line == NULL)
		return (-1);
	if (initialize_elements(fd, line, &dict, &data) == FALSE)
		return (-1);
	while (TRUE)
	{
		dkix = set_data_inline(data, line);
		if (DKIX_ACTIVE(dkix))
			return ((int)(DKIX(dkix)));
		if (DKIX_ERROR(dkix))
			return (-1);
		read_bytes = read_data(fd, data);
		if (read_bytes < 0)
			return (-1);
		if (read_bytes == 0)
			return (del_data_indict(fd, dict, &data) == TRUE ? 0 : -1);
	}
}
