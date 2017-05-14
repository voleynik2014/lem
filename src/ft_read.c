/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:19:23 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:34:48 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_lem	*ft_search_room(t_data *data, char *source)
{
	int	i;

	i = -1;
	while (data->rooms[++i])
		if (ft_strequ(data->rooms[i]->name, source))
			return (data->rooms[i]);
	exit(ft_printf("Can`t find a room(\n") - 18);
}

int 	ft_check_dubles(t_lem *room, t_lem *room2, int *num)
{
	int i;

	i = -1;
	while(room->links[++i])
    {
        if ((i - 1) == room->link_size)
            ft_realloc_current_room(room);
        if (ft_strequ(room->links[i]->name, room2->name))
            return (FALSE);
    }
	(*num) = i;
	return (TRUE);
}

void	ft_read_links2(t_data *data, char *line)
{
	char	**tmp;
	t_lem	*room1;
	t_lem	*room2;
	int		i;

	tmp = ft_strsplit(line, '-');
    i = -1;
    while (tmp[++i])
        ;
    if (i != 2)
        exit(ft_printf("incorrect links\n") - 15);
	room1 = ft_search_room(data, tmp[0]);
	room2 = ft_search_room(data, tmp[1]);
    i = -1;
    while (tmp[++i])
        free(tmp[i]);
	i = -1;
	if (ft_check_dubles(room1, room2, &i))
		room1->links[i] = room2;
	i = -1;
	if (ft_check_dubles(room2, room1, &i))
		room2->links[i] = room1;
}

void	ft_read_links(t_data *data, char *line)
{
	ft_read_links2(data, line);
	while (get_next_line(data->fd, &line))
	{
		if ((line[0] == '#' && line[1] != '#') || !line)
			ft_strdel(&line);
		else if (!*line)
			break ;
		else
			ft_read_links2(data, line);
	}
}

int	ft_read_start_end_block(t_data *data, char *line, int *i)
{
	if (ft_strequ(line, "##end"))
	{
		if (data->end_room)
			exit(ft_printf("Error:double end\n") - 16);
        free(line);
		get_next_line(data->fd, &line);
		data->rooms[(*i)] = ft_create_room(data, line);
		data->end_room = data->rooms[(*i)];
        (*i) += 1;
		return (TRUE);
	}
	else if (ft_strequ(line, "##start"))
	{
		if (data->start_room)
			exit(ft_printf("Error:double start\n") - 18);
        free(line);
		get_next_line(data->fd, &line);
		data->rooms[(*i)] = ft_create_room(data, line);
		data->start_room = data->rooms[(*i)];
        (*i) += 1;
		return (TRUE);
	}
	return (FALSE);
}

int		ft_read_line(t_data *data, char *line)
{
	int i;

	i = 0;
	while (get_next_line(data->fd, &line))
	{
		if ((line[0] == '#' && line[1] != '#') || !line)
			ft_strdel(&line);
		else if (ft_strchr(line, '-'))
        {
			ft_read_links(data, line);
            return (TRUE);
		}
		else if (ft_read_start_end_block(data, line, &i))
			sleep(999);
		else
		{
            data->rooms[i++] = ft_create_room(data, line);
			sleep(999);
			if (i % 100 == 0 && i != 0)
				data->rooms = ft_realloc_array_rooms(data, i, i + 100);
        }
        free(line);
    }
    free(line);
    exit(ft_printf("No links\n") - 8);
	return (FALSE);
}
