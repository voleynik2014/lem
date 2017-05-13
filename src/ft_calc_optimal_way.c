/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calc_optimal_way.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/04 20:29:57 by voliynik          #+#    #+#             */
/*   Updated: 2017/05/04 20:33:21 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_flow	*create_flow(t_data *data)
{
	t_flow	*flow;
	int		way_size;

	way_size = 10;
	flow = (t_flow *)malloc(sizeof(t_flow));
	flow->ways = (t_way **)malloc(sizeof(t_way *) * way_size);
	flow->ways = NULL;
	return (flow);
}
//
//void	realloc_flows(t_data *data, int num)
//{
//	int		i;
//	t_flow	**old;
//
//	old = data->all_possible_flows;
//	data->all_possible_flows = (t_flow **)
//		malloc(sizeof(t_flow *) * (num + 100));
//	i = -1;
//	while (++i < num)
//		data->all_possible_flows[i] = old[i];
//	while (i < (num + 100))
//		data->all_possible_flows[i++] = NULL;
//}

//void	calc_all_possible_flows(t_data *data)
//{
//	int	i;
//	int	alloc_size;
//
//	i = -1;
//	alloc_size = 100;
//	data->all_possible_flows = (t_flow **)malloc(sizeof(t_flow *) * alloc_size);
//	while (data->all_possible_ways[++i])
//	{
//		data->all_possible_flows[i] = create_flow(data);
//		if (i >= alloc_size)
//		{
//			realloc_flows(data, alloc_size);
//			alloc_size = alloc_size + 100;
//		}
//	}
//}

void	calc_optimal_way(t_data *data)
{
	int	alloc_size;

	alloc_size = 100;
	data->all_possible_flows = (t_flow **)malloc(sizeof(t_flow *) * alloc_size);
	permutation(data);
	data->tmp = 0;
	ft_how_many(data);
}
