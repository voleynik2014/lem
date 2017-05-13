
#include "lem_in.h"

t_lem	*ft_realloc_current_room(t_lem *current_room)
{
	t_lem	*new_room;
	int		i;
	int		new_size;

	new_size = current_room->link_size + 21;
	new_room = (t_lem *)malloc(sizeof(t_lem));
	new_room->name = ft_strdup(current_room->name);
	new_room->x = current_room->x;
	new_room->y = current_room->y;
	new_room->links = (t_lem **)malloc(sizeof(t_lem *) * new_size);
	i = -1;
	while (++i < current_room->link_size)
		new_room->links[i] = current_room->links[i];
	while (i < new_size)
		new_room->links[i++] = NULL;
	new_room->link_size = new_size;
	ft_delete_room(current_room);
	return (new_room);
}

t_lem	**ft_realloc_array_rooms(t_data *data, int old_num, int new_num)
{
	int i;
	t_lem **new_arr_rooms;

	new_arr_rooms = (t_lem **)malloc(sizeof(t_lem *) * new_num);
	i = -1;
	while (++i < old_num)
		new_arr_rooms[i] = data->rooms[i];
	while (i < new_num)
		new_arr_rooms[i++] = NULL;
//	delete
	return (new_arr_rooms);
}

t_way	**ft_realloc_ways(t_data *data, int new_size)
{
	t_way	**new_way;
	int		i;
//	int		new_size;

//	new_size = data->point + 101;
	new_way = (t_way **)malloc(sizeof(t_way *) * new_size);
	i = -1;
	while (++i < data->point)
		new_way[i] = data->all_possible_ways[i];
	while (i < new_size)
		new_way[i++] = NULL;
	ft_delete_way(data->all_possible_ways);
	return (new_way);
}

t_way	**ft_realloc_ways_stack(int old_size ,int new_size, t_way **stack)
{
	t_way	**new_way;
	int		i;

	new_way = (t_way **)malloc(sizeof(t_way *) * new_size);
	i = -1;
	while (++i < old_size)
		new_way[i] = stack[i];
	while (i < new_size)
		new_way[i++] = NULL;
//	free(stack);
	return (new_way);
}

t_flow	**ft_realloc_flows(t_data *data)
{
	t_flow	**new_flow;
	int		i;
	int		new_size;

	new_size = data->tmp + 101;
	new_flow = (t_flow **)malloc(sizeof(t_flow *) * new_size);
	i = -1;
	while (++i < data->tmp)
		new_flow[i] = data->all_possible_flows[i];
	while (i < new_size)
		new_flow[i++] = NULL;
//	ft_delete_flow(data->all_possible_flows);
	return (new_flow);
}