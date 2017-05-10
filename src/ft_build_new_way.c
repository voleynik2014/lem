
#include <lem_in.h>

t_way   *ft_save_road(t_data *data, t_lem **rooms_reserved)
{
    t_way *res_way;
    int i;

    i = -1;
    res_way = (t_way *)malloc(sizeof(t_way ) * data->count_rooms_in_theway + 1);
//	data->count_rooms_in_theway = 0;
//    while (rooms_reserved[++i])
//       res_way[i] = rooms_reserved[i];
//    res_way[i] = NULL;
    res_way->room = (t_lem **)malloc(sizeof(t_lem *) * 101);
    while (rooms_reserved[++i])
        if (rooms_reserved[i + 1])
            res_way->room[i] = rooms_reserved[i + 1];
    res_way->room[i - 1] = NULL;
    i = -1;
    ft_printf("RESULT:");
    while (res_way->room[++i])
        ft_printf("-%s", res_way->room[i]->name);
    ft_printf("\n");
    res_way->performance = data->count_rooms_in_theway - 2;
    i = -1;
    while (data->rooms_reserved[++i]);
    data->rooms_reserved[i - 1] = NULL;
    data->count_rooms_in_theway--;
    res_way->id = data->point;
    ft_printf("%d - %d\n", res_way->id, res_way->performance);
    return (res_way);
}

int     no_repeat(t_data *data, t_lem *current_point)
{
    int i;

    i = -1;
    while(data->rooms_reserved[++i])
        if (ft_strequ(data->rooms_reserved[i]->name, current_point->name))
            return (0);
    return (1);

}

void    build_new_way(t_data *data, t_lem *current_point)
{
    int i;

    i = -1;
    while (data->rooms_reserved[++i])
        ;
//		ft_printf("%s-", data->rooms_reserved[i]->name);
//	ft_printf("\t\t\t +%s\n", current_point->name);
    data->rooms_reserved[i++] = current_point;
	data->count_rooms_in_theway++;
    data->rooms_reserved[i] = NULL;
    if (ft_strequ(current_point->name, data->rooms[data->count_rooms - 1]->name))
	{
        data->all_possible_ways[data->point++] = ft_save_road(data, data->rooms_reserved);
		return ;
		if (data->point == 10)
			sleep(999);
	}
	i = -1;
    while (current_point->links[++i])
        if (no_repeat(data, current_point->links[i]))
           build_new_way(data, current_point->links[i]);
	i = -1;
    while (data->rooms_reserved[++i]);
    data->rooms_reserved[i - 1] = NULL;
    data->count_rooms_in_theway--;
}
