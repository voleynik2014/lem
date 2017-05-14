/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lem_in.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:39:51 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:44:13 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <lem_in.h>

void	get_num_ants(t_data *data)
{
	char	*line;
	int		i;

	i = -1;
	data->rooms = (t_lem **)malloc(sizeof(t_lem *) * 101);  // realloc rooms when them more then 100 pieces// checked
	while (++i < 101)
		data->rooms[i] = NULL;
	if (!get_next_line(data->fd, &line)) // проверить валидность что бы были только цифры  // checked
		line = NULL;
	if (check_valid_count_ants(line))
		data->total_ants = atoi(line);
	ft_strdel(&line);
    if (!ft_read_line(data, line))
        exit(ft_printf("Incorrect input\n") - 15);
    if (!data->start_room || !data->end_room)
        exit(ft_printf("Lost start or end room\n") - 22);
}

void	ft_lem_in(void)
{
	t_data	*data;
	int		i;

	i = -1;
	data = (t_data *)malloc(sizeof(t_data) * 1);
	ft_bzero(data, sizeof(t_data));
	data->fd = open("test.txt", O_RDONLY);
	get_num_ants(data);
//	ft_print_map(data, data->rooms);
    sleep(999);
	data->rooms_reserved = (t_lem **)
		malloc(sizeof(t_lem *) * data->count_rooms + 1);
	while (++i < data->count_rooms)
		data->rooms_reserved[i] = NULL;
	data->all_possible_ways = (t_way **)malloc(sizeof(t_way *) * 101);
	build_new_way(data, data->rooms[0]);
    i = -1;
    while(data->rooms_reserved[++i])
        free(data->rooms_reserved[i]);
	data->start_room->count_ants = 1;
	calc_optimal_way(data);
}

int		main(void)
{
	clock_t start, end;
	start = clock();
	ft_lem_in();
	end = clock();

	printf("The above code block was executed in %.4f second(s)\n", ((double) end - start) / ((double) CLOCKS_PER_SEC));
    sleep(999);
	return (0);
}
