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

void	ft_print_rooms(t_way *res_way)
{
	int i;

	i = -1;
	while (res_way->room[++i])
		ft_printf("-%s", res_way->room[i]->name);
	while (++i < 10)
		ft_printf("  ");
	ft_printf(" --> ");
	ft_printf("%d - %d\n", res_way->id, res_way->performance);
}

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
//	ft_printf("RESULT:");
//	ft_print_rooms(res_way);
	return (res_way);
}

int		no_repeat(t_data *data, t_lem *current_point)
{
	int i;

	i = -1;
	while (data->rooms_reserved[++i])
		if (ft_strequ(data->rooms_reserved[i]->name, current_point->name))
			return (FALSE);
	return (TRUE);
}

void	build_new_way(t_data *data, t_lem *current_point) {
	int i;

	i = -1;
	while (data->rooms_reserved[++i]);
	data->rooms_reserved[i++] = current_point;
	data->count_rooms_in_theway++;
	data->rooms_reserved[i] = NULL;
	if (ft_strequ(current_point->name,
				  data->rooms[data->count_rooms - 1]->name)) {
		if ((data->point % 100) == 0)
			data->all_possible_ways = ft_realloc_ways(data, data->point + 101);
		data->all_possible_ways[data->point++] =
				ft_save_road(data, data->rooms_reserved);
		return;
	}
	i = -1;
	while (current_point->links[++i])
	{
		if ((i - 1) == current_point->link_size)
			ft_realloc_current_room(current_point);
		if (no_repeat(data, current_point->links[i]))
			build_new_way(data, current_point->links[i]);
	}
	i = -1;
	while (data->rooms_reserved[++i])
		;
	data->rooms_reserved[i - 1] = NULL;
	data->count_rooms_in_theway--;
}
