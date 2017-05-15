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

void	calc_optimal_way(t_data *data)
{
	int	alloc_size;

	alloc_size = 100;
	data->all_possible_flows = (t_flow **)malloc(sizeof(t_flow *) * alloc_size);
	permutation(data);
	data->tmp = 0;
	ft_how_many(data);
}
