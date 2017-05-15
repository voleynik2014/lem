#include "lem_in.h"

int		check_valid_count_ants(char *line)
{
	int i;

	i = -1;
	if (!line || !*line)
	{
		ft_strdel(&line);
		exit(ft_printf("Invalid input\n") - 14);
	}
	while (line[++i])
		if (!ft_isdigit(line[i])) {
			exit(ft_printf("Invalid number\n") - 15);
		}
	return (TRUE);
}

int     ft_valid_ways(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (data->final_ways->ways[++i])
	{
		j = -1;
		while(data->final_ways->ways[i]->room[++j])
			if (data->final_ways->ways[i]->room[j]->count_ants)
				return (TRUE);
	}
	return (FALSE);
}