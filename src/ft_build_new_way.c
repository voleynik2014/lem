/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_build_new_way.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:36:52 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:39:42 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

t_way	*ft_save_road(t_data *data, t_lem **rooms_reserved)
{
	t_way	*res_way;
	int		i;

	i = -1;
	res_way = (t_way *)malloc(sizeof(t_way ) * data->count_rooms_in_theway + 1);
	res_way->room = (t_lem **)malloc(sizeof(t_lem *) * 101);
	while (rooms_reserved[++i])
		if (rooms_reserved[i + 1])
			res_way->room[i] = rooms_reserved[i];
	res_way->room[i - 1] = NULL;
	res_way->performance = data->count_rooms_in_theway - 1;
	i = -1;
	while (data->rooms_reserved[++i])
		;
	data->rooms_reserved[i - 1] = NULL;
	data->count_rooms_in_theway--;
	res_way->id = data->point;
	return (res_way);
}

int		without_repeat(t_data *data, t_lem *current_point)
{
	int i;

	i = -1;
	while (data->rooms_reserved[++i])
		if (ft_strequ(data->rooms_reserved[i]->name, current_point->name))
			return (FALSE);
	return (TRUE);
}

void	ft_build_start_to_end_room(t_data *data)
{
	int i;

	i = -1;
	while(data->start_room->links[i])
	{
//		if (ft_strequ(data->start_room->links[i]->name, data->end_room->name))
//		{
//			data->count_rooms_in_theway = 2;
//			ft_save_road(data, )
//		}
	}
}

void	build_new_way(t_data *data, t_lem *current_point)
{
	int i;

	i = -1;
	while (data->rooms_reserved[++i]);
	data->rooms_reserved[i++] = current_point;
	data->count_rooms_in_theway++;
	data->rooms_reserved[i] = NULL;
	if (ft_strequ(current_point->name,
				  data->end_room->name)) {
		if ((data->point % 100) == 0)
			data->all_possible_ways = ft_realloc_ways(data, data->point + 101);
		data->all_possible_ways[data->point++] =
				ft_save_road(data, data->rooms_reserved);
		return;
	}
	i = -1;
	while (current_point->links[++i])
	{
		if (without_repeat(data, current_point->links[i]))
			build_new_way(data, current_point->links[i]);
	}
	i = -1;
	while (data->rooms_reserved[++i])
		;
	data->rooms_reserved[i - 1] = NULL;
	data->count_rooms_in_theway--;
}
