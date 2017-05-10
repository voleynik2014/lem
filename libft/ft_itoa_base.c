/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 14:18:20 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 14:54:54 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		ft_numsize(unsigned long long n, size_t set)
{
	int i;

	i = 1;
	while (n >= set)
	{
		i++;
		n /= set;
	}
	return (i);
}

void			ft_recursion(unsigned long long n, char *tmp,
				int *i, t_print *sel)
{
	int		alp;

	alp = 'a';
	if (sel->toggle)
		alp = sel->toggle;
	if (n >= sel->set)
	{
		ft_recursion(n / sel->set, tmp, i, sel);
		ft_recursion(n % sel->set, tmp, i, sel);
	}
	else if (n > 9 && n < sel->set)
	{
		tmp[*i] = alp + (n - 10);
		(*i)++;
	}
	else
	{
		tmp[*i] = n + '0';
		(*i)++;
	}
}

char			*ft_itoa_base_set(unsigned long long n, size_t set,
				char toggle, t_print *sel)
{
	char	*tmp;
	int		i;

	sel->set = set;
	sel->toggle = toggle;
	i = 0;
	tmp = (char *)malloc(sizeof(char) * ft_numsize(n, set) + 1);
	ft_recursion(n, tmp, &i, sel);
	tmp[i] = '\0';
	return (tmp);
}
