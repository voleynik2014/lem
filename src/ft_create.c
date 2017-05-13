/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:46:13 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:46:51 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_lem	*ft_create_room(t_data *data, char *line)
{
	char	**arr;
	t_lem	*room;
	int		i;

	room = (t_lem *)malloc(sizeof(t_lem));
	ft_bzero(room, sizeof(t_lem));
	arr = ft_strsplit(line, ' ');
	room->name = ft_strdup(arr[0]);
	room->x = ft_atoi(arr[1]);
	room->y = ft_atoi(arr[2]);
	room->links = (t_lem **)malloc(sizeof(t_lem *) * 21);
	i = -1;
	while (++i < 21)
		room->links[i] = NULL;
	room->link_size = 21;
	data->count_rooms++;
	return (room);
}
