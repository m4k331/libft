/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahugh <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/05 19:39:19 by ahugh             #+#    #+#             */
/*   Updated: 2019/11/20 13:23:31 by ahugh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int			initialize_elements(int fd, \
										char **line, \
										t_dict *dict, \
										t_vector **data)
{
	char			*key;
	int				dkix;

	*line = NULL;
	dkix = TRUE;
	dict = (dict == NULL ? ft_dictnew(GNL_INIT_DICT_SIZE) : dict);
	if (dict == NULL)
		return (FALSE);
	key = ft_itoa_base(fd, 16);
	*data = ft_dictget(dict, key);
	if (*data == NULL)
	{
		*data = ft_vnew(GNL_INIT_VEC_SIZE, sizeof(char));
		if (*data == NULL || ft_dictset(dict, key, *data) == FALSE)
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
	char			*nl_character;
	char			*begin;

	begin = (char*)data->con + data->iter;
	nl_character = (char*)ft_memchr(begin, '\n', data->head - (size_t)begin);
	if (nl_character == NULL)
	{
		data->iter = data->head;
		return (0);
	}
	dkix = (size_t)nl_character - (size_t)data->con;
	*line = ft_strnew(dkix);
	if (*line)
	{
		ft_memcpy(*line, data->con, dkix);
		data->con += dkix;
	}
	dkix |= (*line == NULL ? MASK_ERROR : MASK_ACTIVE);
	return (dkix);
}

static int			read_data(int fd, t_vector *data)
{
	long			free;
	int				offset;
	int				read_bytes;

	free = data->size - data->head;
	offset = MIN_READ_BYTES;
	if (free < offset)
	{
		data->head -= (size_t)data->con;
		ft_memmove((void*)data->const_con, data->con, data->head);
		data->iter = 0;
		if (ft_vresize(data, (data->size + offset) * 2) == FALSE)
			return (-1);
	}
	while (offset > 0)
	{
		read_bytes = read(fd, data->con, BUFF_SIZE);
		if (read_bytes < 1)
			return (read_bytes);
		offset -= read_bytes;
		data->con += read_bytes;
	}
	return (-offset + MIN_READ_BYTES);
}

static int			del_data_indict(int fd, \
									char **line, \
									t_dict *dict, \
									t_vector **data)
{
	char			*key;
	size_t			dkix;

	dkix = set_data_inline(*data, line);
	if (DKIX_ERROR(dkix))
		return (FALSE);
	key = ft_itoa_base(fd, 16);
	if (key == NULL)
		return (FALSE);
	ft_vdel(data);
	dkix = ft_dictunset(dict, key, NULL);
	ft_memdel((void**)&key);
	return (dkix);
}

int					get_next_line(const int fd, char **line)
{
	static t_dict	*dict = NULL;
	t_vector		*data;
	size_t			dkix;
	int				read_bytes;

	if (fd < MIN_FD || BUFF_SIZE < MIN_BUFF_SIZE || line == NULL)
		return (-1);
	if (initialize_elements(fd, line, dict, &data) == FALSE)
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
			return (del_data_indict(fd, line, dict, &data) == TRUE ? 0 : -1);
	}
}
