/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   permutation.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:25:24 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:29:49 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#include <lem_in.h>

int		ft_wayequ(t_way *src1, t_way *src2)
{
	int i;
	int j;

	i = -1;
	while (src1->room[++i])
	{
		if (!(src2->room[1]))
			return (FALSE);
		j = 0;
		while (src2->room[++j])
			if (ft_strequ(src1->room[i]->name, src2->room[j]->name))
				return (FALSE);
	}
	return (TRUE);
}

int		check(t_way *posible_way, t_flow *stack)
{
	int j;

	j = -1;
	while (stack->ways[++j])
	{
		if (!(ft_wayequ(stack->ways[j], posible_way)))
			return (FALSE);
	}
	return (TRUE);
}

void	ft_print_flows(t_flow *stack, t_data *data)
{
	int i;

	printf("--------------------\n");
	i = -1;
	while (stack->ways[++i])
		ft_print_rooms(stack->ways[i]);
	printf("%d--------------------\n", stack->performance);
	printf("\n");
}

void	ft_save_flow(t_flow *stack, t_data *data)
{
	int i;
	int total_perform;
	int max_perform;

	if ((data->tmp % 100) == 0)
		data->all_possible_flows = ft_realloc_flows(data);
	data->all_possible_flows[data->tmp] = (t_flow *)malloc(sizeof(t_flow) * 1);
	data->all_possible_flows[data->tmp]->ways = (t_way **)malloc(sizeof(t_way *) * data->count_rooms);
	i = -1;
	while (++i < data->count_rooms)
		data->all_possible_flows[data->tmp]->ways[i] = NULL;
	i = -1;
	total_perform = 0;
	max_perform = 0;
	while (stack->ways[++i])
	{
		if (i % data->count_rooms == 0 && i != 0 )
			data->all_possible_flows[data->tmp]->ways = ft_realloc_ways_stack(i, i + data->count_rooms, data->all_possible_flows[data->tmp]->ways);
		data->all_possible_flows[data->tmp]->ways[i] = stack->ways[i];
//		ft_print_rooms(stack->ways[i]);
		total_perform += stack->ways[i]->performance;
		if (data->all_possible_flows[data->tmp]->ways[i]->performance >
				max_perform)
			max_perform = data->all_possible_flows[data->tmp]->
				ways[i]->performance;
	}
	data->all_possible_flows[data->tmp]->quantity_ways = i - 1;
	data->all_possible_flows[data->tmp]->performance = ft_ceil(total_perform, data->total_ants,i);
	data->all_possible_flows[data->tmp]->max_perf_rooms = max_perform;
	data->tmp++;
//	ft_print_flows(data->all_possible_flows[data->tmp], data);
}

void	rec(t_flow *stack, int *pos, t_data *data)
{
	int i;

	i = -1;
	while (data->all_possible_ways[++i])
	{
		if (check(data->all_possible_ways[i], stack))
		{
			if (((*pos) % data->count_rooms) == 0 && (*pos) != 0)
				stack->ways = ft_realloc_ways_stack((*pos), (*pos) + data->count_rooms, stack->ways);
			stack->ways[(*pos)++] = data->all_possible_ways[i];
			stack->ways[(*pos)] = NULL;
			ft_save_flow(stack, data);
			rec(stack, pos, data);
		}
	}
	(*pos) -= 1;
	stack->ways[(*pos)] = NULL;
}

void	**permutation(t_data *data)
{
	int		pos;
	int		i;
	t_flow	*stack;


	stack = (t_flow *)malloc(sizeof(t_flow) * 1);
	ft_bzero(stack, sizeof(t_flow));
	stack->ways = (t_way **)malloc(sizeof(t_way *) * data->count_rooms);
	i = -1;
	while (++i < data->count_rooms)
		stack->ways[i] = NULL;
	pos = 0;
	rec(stack, &pos, data);
	return (FALSE);
}
