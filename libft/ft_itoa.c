/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/29 13:15:12 by voliynik          #+#    #+#             */
/*   Updated: 2016/12/01 12:09:47 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_numdefiner(int n)
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

static void		ft_recursion(int n, char *str, int *i)
{
	if (n < 0)
	{
		str[*i] = '-';
		(*i)++;
		n = -n;
	}
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

char			*ft_itoa(int n)
{
	char	*dup;
	char	*ret;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_numdefiner(n) + 1));
	if (!dup)
		return (NULL);
	ret = dup;
	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	if (!n)
	{
		dup[0] = '0';
		dup[1] = '\0';
	}
	i = 0;
	ft_recursion(n, dup, &i);
	dup[i] = '\0';
	return (ret);
}
