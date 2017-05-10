
#include <lem_in.h>

void	get_num_ants(t_data *data)
{
	char	*line;

	data->rooms = (t_lem **)malloc(sizeof(t_lem *) * 101);
    int i = -1;
    while (++i < 101)
        data->rooms[i] = NULL;
	while (get_next_line(data->fd, &line))
	{
		if (ft_strequ(line, "##start"))
		{
			ft_read_line(data, line);
			break ;	
		}
		if (line[0] == '#' && line[1] != '#')
			ft_strdel(&line);
		else
			exit (ft_printf("Incorrect input\n") - 15);
	}
}

void	ft_print_map(t_data *data, t_lem **rooms)
{
	int i;
	int	j;

	i = -1;
    ft_printf("%s, ", data->rooms[0]->links[0]->name);
	while (data->rooms[++i])
	{
		ft_printf("room \"%s\" has links:\t", data->rooms[i]->name);
		j = -1;
		while(data->rooms[i]->links[++j])
//
			ft_printf("%s, ", data->rooms[i]->links[j]->name);
		ft_printf("\n");
	}
}

void	ft_lem_in()
{
	t_data *data;

	data = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero(data, sizeof(t_data));
	data->fd = open("test.txt", O_RDONLY);
	ft_printf("FD%d\n", data->fd);
	get_num_ants(data);
	ft_print_map(data, data->rooms);
//	sleep(999);
	ft_printf("FD%d\n", data->fd);
    data->rooms_reserved = (t_lem **)malloc(sizeof(t_lem *) * data->count_rooms + 1);
    int i = -1;
    while (++i < data->count_rooms)
        data->rooms_reserved[i] = NULL;
//    bzero(data->rooms_reserved, sizeof(t_lem *));
    data->all_possible_ways = (t_way **)malloc(sizeof(t_way *) * 101);
//	bzero(data->roads_reserved, sizeof(t_lem **));
    build_new_way(data, data->rooms[0]);
	ft_printf("%d\n", data->count_rooms_in_theway);
//    data->final_ways = (t_lem **)malloc(sizeof(t_lem *) * 11);

    calc_optimal_way(data);
//	ft_printf("%s, %d, %d\n", data->rooms[0]->name, data->rooms[0]->x, data->rooms[0]->y);
}

int main(void)
{
	ft_lem_in();
	return (0);
}
