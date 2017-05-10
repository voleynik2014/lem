#include <lem_in.h>

//int     repeat(t_data *data, t_way *current)
//{
//    int i;
//    int y;
//    int x;
//
////    if (!res->room && )
////        return (TRUE);
//    i = -1;
//    while(data->final_ways[++i]) {
//        y = -1;
//        while (data->final_ways[i]->room[++y]) {
////            x = -1;
////            while (current->room[++x])
//                if (ft_strequ(data->final_ways[i]->room[y]->name, current->room[y]->name))
//                   return (FALSE);
//        }
//    }
//    return (TRUE);
//}
//
//void   *ft_delete_way(t_data *data, int i)
//{
//    while (data->all_possible_ways[i]) {
//        if (data->all_possible_ways[i + 1])
//            data->all_possible_ways[i] = data->all_possible_ways[i + 1];
//        i++;
//    }
//}
//
//t_way   *find_shortest_way(t_data *data)
//{
//    int i;
//    t_way *res;
//    int     delete;
//
//    res = (t_way *)malloc(sizeof(t_way));
//    res->performance = 2147483647;
//    i = -1;
//    delete = -1;
//    while (++i < data->point)
//    {
//        if (data->all_possible_ways[i]->performance < res->performance)
//            if (repeat(data, data->all_possible_ways[i])) {
//                res = data->all_possible_ways[i];
//                delete = i;
//            }
//    //            data->all_possible_ways[i] = NULL;
//    }
//    ft_delete_way(data, delete);
//    return (res);
//}

//t_way   *realloc_way(t_data *data, int num)
//{
//    t_way **ways;
//
//    ways = (t_way **)malloc(sizeof(t_way *) * num);
//
//}

//t_flow *calc_something(t_data *data)
//{
//    int y;
//    int res;
//
//    res = 0;
//    data->final_ways = (t_flow *)malloc(sizeof(t_flow ));
//    data->final_ways->ways = (t_way **)malloc(sizeof(t_way *) * 10);
//    y = -1;
//    while (1) {
//        if (y >= res)
//            data->final_ways->ways = realloc_way(data, res + 10);
//        if (!(data->final_ways->ways[++y] = find_shortest_way(data)))
//            break ;
//    }
//}
t_flow   *create_flow(t_data *data)
{
    t_flow *flows;

    flows = (t_flow *)malloc(sizeof(t_flow) * 10);
    return (flows);
}

void  realloc_flows(t_data *data, int num)
{
    int   i;
    t_flow **old;

    old = data->all_possible_flows;
    data->all_possible_flows = (t_flow **)malloc(sizeof(t_flow *) * (num + 100));
    i = -1;
    while (++i < num)
        data->all_possible_flows[i] = old[i];
    while (i < (num + 100))
        data->all_possible_flows[i++] = NULL;
}

void    calc_all_possible_flows(t_data *data)
{
    int i = -1;
    int alloc_size;

    alloc_size = 50;
    data->all_possible_flows = (t_flow **)malloc(sizeof(t_flow *) * alloc_size);
    while (data->all_possible_ways[++i]) {
        data->all_possible_flows[i] = create_flow(data);
        if (i >= alloc_size) {
            realloc_flows(data, alloc_size);
            alloc_size = alloc_size + 100;
        }
        if (data->all_possible_ways[i])
            calc_all_possible_flows(data);
    }
}

void    calc_optimal_way(t_data *data)
{
    // possibly, will better did not created array of ways, maybe better create just one array to write ways and just rewrite them when we we`ll known that worse then current way)

//    t_flow *final_ways;
//    t_flow **all_flows;
//    data->final_ways = calc_something(data);
    int i;

    calc_all_possible_flows(data);
    i = -1;
    while (++i < 2)
    ft_printf("Final: %d\n", data->final_ways->ways[i]->id);
}