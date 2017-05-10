/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_ll.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:01:18 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 14:02:31 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static long long	ft_numdefiner(long long n)
{
	int i;

	i = 1;
	if (n < 0)
	{
		n = -n;
		i++;
	}
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void			ft_recursion(long long n, char *str, int *i)
{
	if (n < 0)
		n = -n;
	if (n > 9)
	{
		ft_recursion(n / 10, str, i);
		ft_recursion(n % 10, str, i);
	}
	else
	{
		str[*i] = n + '0';
		(*i)++;
	}
}

char				*ft_itoa_ll(long long n)
{
	char	*dup;
	char	*ret;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_numdefiner(n) + 1));
	if (!dup)
		return (NULL);
	ret = dup;
	if (n == (-9223372036854775807 - 1))
		return (ft_strdup("9223372036854775808"));
	if (!n)
	{
		dup[0] = '0';
		dup[1] = '\0';
		return (ret);
	}
	i = 0;
	ft_recursion(n, dup, &i);
	dup[i] = '\0';
	return (ret);
}
