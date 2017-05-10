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

int		split(t_get *data, char **line, char c)
{
	char	*point;
	char	*tmp;
	int		i;

//	if (line)
//		*line = ft_strnew(1);
	if (!data->buffer || !*data->buffer)
		return (0);
	if (c == '\0')
	{
		ft_strdel(line);
		*line = ft_strdup(data->buffer);
		ft_strclr(data->buffer);
		return (1);
	}
	if (!(point = ft_strchr(data->buffer, c)))
		return (0);
	i = point - data->buffer;
//	ft_strdel(line);
//	*line = ft_strnew(i + 1);
	*line = ft_strncpy(ft_strnew(i + 1), data->buffer, i);
	tmp = ft_strdup(point + 1);
	free(data->buffer);
	data->buffer = tmp;
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
	buff = ft_strnew(BUFF_SIZE + 1);
	if (split(data, line, '\n'))
		return (1);
	while (((n = read(data->fd, buff, BUFF_SIZE)) > 0))
	{
		tmp = ft_strdup(data->buffer);
		free(data->buffer);
		data->buffer = ft_strjoin(tmp, buff);
		free(tmp);
		ft_strclr(buff);
		if (ft_strchr(data->buffer, '\n'))
			break ;
	}
	free(buff);
	if (n < 0)
		return (-1);
	if (split(data, line, '\n') || split(data, line, '\0'))
		return (1);
	return (0);
}
