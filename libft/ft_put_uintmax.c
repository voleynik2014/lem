/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_uintmax.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:54:17 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 11:55:52 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void			ft_put_uintmax(uintmax_t n)
{
	if (n < 10)
		ft_putchar('0' + n);
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

static int		ft_u_numdefiner(uintmax_t n)
{
	int i;

	i = 1;
	while (n >= 10)
	{
		i++;
		n /= 10;
	}
	return (i);
}

static void		ft_u_recursion(uintmax_t n, char *str, int *i)
{
	if (n > 9)
	{
		ft_u_recursion(n / 10, str, i);
		ft_u_recursion(n % 10, str, i);
	}
	else
	{
		str[*i] = n + '0';
		(*i)++;
	}
}

char			*ft_uintmax_toa(uintmax_t n)
{
	char	*dup;
	char	*ret;
	int		i;

	dup = (char *)malloc(sizeof(char) * (ft_u_numdefiner(n) + 1));
	if (!dup)
		return (NULL);
	ret = dup;
	if (!n)
	{
		dup[0] = '0';
		dup[1] = '\0';
	}
	i = 0;
	ft_u_recursion(n, dup, &i);
	dup[i] = '\0';
	return (ret);
}
