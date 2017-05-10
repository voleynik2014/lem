/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 14:51:08 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 16:53:34 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TAB(x) (x == '\f' || x == '\v' || x == '\t' || x == ' ')
#define TAB2(x) (x == '\n' || x =='\r')
#define BAT(x) (x >= '0' && x <= '9')

int			ft_atoi(const char *str)
{
	int i;
	int tmp;
	int op;

	op = 1;
	tmp = 0;
	i = 0;
	while (TAB(str[i]) || TAB2(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && BAT(str[i + 1]))
	{
		if (str[i] == '-')
			op = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + str[i] - '0';
		i++;
	}
	return (tmp * op);
}

long long	ft_atoi_ll(const char *str)
{
	int			i;
	long long	tmp;
	int			op;

	op = 1;
	tmp = 0;
	i = 0;
	while (TAB(str[i]) || TAB2(str[i]))
		i++;
	if ((str[i] == '+' || str[i] == '-') && BAT(str[i + 1]))
	{
		if (str[i] == '-')
			op = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		tmp = tmp * 10 + str[i] - '0';
		i++;
	}
	return (tmp * op);
}
