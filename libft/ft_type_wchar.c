/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_wchar.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:25:21 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 17:14:26 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

size_t				ft_wstrlen(wchar_t *str)
{
	size_t i;

	i = 0;
	while (*str)
	{
		if (*str <= 0x7F)
			i++;
		else if (*str <= 0x7FF)
			i += 2;
		else if (*str <= 0xFFFF)
			i += 3;
		else if (*str <= 0x10FFFF)
			i += 4;
		str++;
	}
	return (i);
}

int					ft_type_wchar(va_list list, int *pos, t_print *select)
{
	wchar_t		*tmp;

	*pos = *pos + 1;
	tmp = va_arg(list, wchar_t *);
	if (tmp == NULL)
	{
		ft_putstr("(null)");
		select->res += ft_strlen("(null)");
		return (1);
	}
	if (select->width || select->prec)
		ft_padding_wstr(select, tmp, ' ');
	else
	{
		ft_putwstr(tmp);
		select->res += ft_wstrlen(tmp);
	}
	return (1);
}

void				ft_putwstr(wchar_t *tmp)
{
	while (*tmp)
		ft_putwchar(*tmp++);
}

static wchar_t		*ft_wstrndup(wchar_t *s1, size_t len)
{
	wchar_t		*tmp;
	size_t		i;
	wchar_t		*point;

	tmp = (wchar_t *)malloc(sizeof(wchar_t) * len + 1);
	point = tmp;
	if (tmp == NULL)
		return (NULL);
	i = ft_wcharlen(*s1);
	while (s1 && i <= len)
	{
		*tmp = *s1;
		s1++;
		i += ft_wcharlen(*s1);
		tmp++;
	}
	*tmp = '\0';
	return (point);
}

void				ft_padding_wstr(t_print *select, wchar_t *tmp, char c)
{
	int		len;
	char	*buff;

	if (select->prec_turn == 1 && !select->prec)
		tmp = ft_wstrndup(L"", 2);
	if (select->prec && (select->prec < ft_wstrlen(tmp)))
		tmp = ft_wstrndup(tmp, select->prec);
	len = select->width - ft_wstrlen(tmp) - select->null;
	buff = ft_strnew(len + 1);
	if (len > 0)
		ft_memset(buff, c, len);
	if (select->flag_minus)
	{
		ft_putwstr(tmp);
		ft_putstr(buff);
	}
	else
	{
		ft_putstr(buff);
		ft_putwstr(tmp);
	}
	select->res += ft_wstrlen(tmp) + (len > 0 ? len : 0);
}
