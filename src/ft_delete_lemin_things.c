#include "lem_in.h"

void	ft_delete_room(t_lem *current_room)
{
	free(current_room);
}

void	ft_delete_way(t_way **current_way)
{
	free(current_way);
}

void	ft_delete_all_ways(t_data *data)
{
	int i;

	i = -1;
	while(data->all_possible_ways[++i])
	{
		free(data->all_possible_ways[i]->room);
		free(data->all_possible_ways[i]);
	}
	free(data->all_possible_ways);
}

void	ft_delete_all_rooms(t_data *data)
{
	int i;

	i = -1;
	while (data->rooms[++i])
	{
		free(data->rooms[i]->links);
		ft_strdel(&data->rooms[i]->name);
		free(data->rooms[i]);
	}
	free(data->rooms);
}

void	ft_delete_all_flows(t_data *data)
{
	int i;

	i = -1;
	while (data->all_possible_flows[++i]) {
		free(data->all_possible_flows[i]->ways);
		free(data->all_possible_flows[i]);
	}
	free(data->all_possible_flows);
}