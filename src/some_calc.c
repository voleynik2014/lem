/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   some_calc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:44:24 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:45:59 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int ft_ceil(int total_perform, int total_ants, int i)
{
	float num;

	num = ((total_perform + total_ants) / (float)i);
	int inum = (int)num;
	if (num == (float)inum)
		return inum;
	return (inum + 1);
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

void	ft_print_current_status(t_data *data)
{
	int i;
	int j;

	i = -1;
	while (data->final_ways->ways[++i])
	{
		j = data->final_ways->ways[i]->performance;
		if (j > 0)
		{
			data->final_ways->ways[i]->room[j]->count_ants = data->final_ways->ways[i]->room[j - 1]->count_ants;
			if ((j - 1) != 0)
				data->final_ways->ways[i]->room[j - 1]->count_ants = 0;
		if (j != 0 && data->final_ways->ways[i]->room[j]->count_ants)
			ft_printf("L%d-%s ",data->final_ways->ways[i]->room[j]->count_ants, data->final_ways->ways[i]->room[j]->name);
		}
	}
}

void	ft_print_final_ways(t_flow *final_ways, t_data *data)
{
	int i;
	int j;
	int end_flag;

	end_flag = 0;
	while (ft_valid_ways(data))
	{
		i = -1;
		ft_print_current_status(data);
		while (data->final_ways->ways[++i])
		{
			j = data->final_ways->ways[i]->performance + 1;
			while (data->final_ways->ways[i]->room[--j])
			{
                if (!(ft_valid_ways(data)) && data->start_room->count_ants )
                    break ;
				if (j > 0)
				{
					data->final_ways->ways[i]->room[j]->count_ants = data->final_ways->ways[i]->room[j - 1]->count_ants;
					if ((j - 1) != 0)
                        data->final_ways->ways[i]->room[j - 1]->count_ants = 0;
					if (j != 0 && j != data->final_ways->ways[i]->performance + 1 && data->final_ways->ways[i]->room[j]->count_ants)
						ft_printf("L%d-%s ",data->final_ways->ways[i]->room[j]->count_ants, data->final_ways->ways[i]->room[j]->name);
                    if (j == data->final_ways->ways[i]->performance + 2)
                        data->end_room->count_ants = 0;
				}
				if (data->start_room->count_ants > data->total_ants && ++end_flag)
					data->start_room->count_ants = 0;
				else if (j == 0 && !end_flag)
                   data->start_room->count_ants++;
			}
		}
		ft_printf("\n");
	}
}

void		ft_how_many(t_data *data)
{
	int i;
	int j;

	data->final_ways = (t_flow *)malloc(sizeof(t_flow) * 1);
	ft_bzero(data->final_ways, sizeof(t_flow));
	data->final_ways = data->all_possible_flows[0];
	i = 0;
	while (data->all_possible_flows[++i])
	{
		if (data->all_possible_flows[i]->performance < data->final_ways->performance)
		data->final_ways = data->all_possible_flows[++i];
	}
	i = -1;
	while (data->final_ways->ways[++i])
	{
		j = -1;
		while (data->final_ways->ways[i]->room[++j])
			;
		data->final_ways->ways[i]->room[j] = data->rooms[data->count_rooms - 1];
	}
	ft_printf("final-ways\n");
	ft_print_flows(data->final_ways, data);
	ft_print_final_ways(data->final_ways, data);
}
