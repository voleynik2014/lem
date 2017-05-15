/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/16 13:19:27 by voliynik          #+#    #+#             */
/*   Updated: 2017/01/21 17:49:45 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_get	*ft_sort_list(int fd, t_get **begin, t_get *data)
{
	data = *begin;
	while (data && data->fd != fd)
		data = data->next;
	if (!data)
	{
		data = (t_get *)malloc(sizeof(t_get));
		data->fd = fd;
		data->buffer = ft_strnew(BUFF_SIZE + 1);
		data->next = *begin;
		*begin = data;
	}
	return (data);
}

int		split(char **buffer, char **line, char c)
{
	char	*point;
	char	*tmp;
	int		i;

//	if (line)
//		*line = ft_strnew(1);
	if (!*buffer || !**buffer)
		return (0);
	if (c == '\0')
	{
//		ft_strdel(line);
		*line = ft_strdup(*buffer);
		ft_strclr(*buffer);
		return (1);
	}
	if (!(point = ft_strchr(*buffer, c)))
		return (0);
	i = point - *buffer;
//	ft_strdel(line);
	*line = ft_strnew(i + 1);
	*line = ft_strncpy(*line, *buffer, i);
	tmp = ft_strdup(point + 1);
	free(*buffer);
	*buffer = tmp;
	return (1);
}

int		get_next_line(int fd, char **line)
{
	static	t_get	*begin;
	t_get			*data;
	int				n;
	char			*buff;
	char			*tmp;

	data = NULL;
	data = ft_sort_list(fd, &begin, data);
	if (split(&data->buffer, line, '\n'))
		return (1);
	buff = ft_strnew(BUFF_SIZE + 1);
	while (((n = read(data->fd, buff, BUFF_SIZE)) > 0))
	{
		buff[n] = '\0';
		tmp = ft_strdup(data->buffer);
		free(data->buffer);
		data->buffer = ft_strjoin(tmp, buff);
		ft_strdel(&tmp);
		ft_strdel(&buff);
		if (ft_strchr(data->buffer, '\n'))
			break ;
	}
	ft_strdel(&buff);
	if (n < 0)
		return (-1);
	if (split(&data->buffer, line, '\n') || split(&data->buffer, line, '\0'))
		return (1);
	return (0);
}
