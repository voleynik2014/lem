/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:30:04 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 15:20:51 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_specifiers(const char *format, va_list list, int *pos,
		t_print *select)
{
	while ((ft_check_flags(format, pos, select)) ||
			(ft_check_width(format, list, pos, select)) ||
			(ft_check_precision(format, list, pos, select)) ||
			(ft_check_mod(format, pos, select)))
		;
	if (ft_check_type(format, list, pos, select))
		return (1);
	return (0);
}

int		ft_doformat(const char *restrict format, va_list ap, int pos)
{
	t_print		select;

	ft_bzero(&select, sizeof(select));
	select.res = 0;
	while (format[pos])
	{
		ft_bzero_struct(&select);
		if (format[pos] == '{')
			ft_color(format, &pos);
		if (format[pos] && format[pos] != '%')
			ft_type_c(ap, &pos, &select, format[pos]);
		if (format[pos] == '%' && format[pos + 1])
			if (!ft_check_specifiers(format, ap, &pos, &select))
				if (format[pos + 1] && ++pos)
					ft_type_c(ap, &pos, &select, format[pos]);
		if (!format[pos])
			break ;
		pos++;
	}
	va_end(ap);
	return (select.res);
}

int		ft_printf(const char *restrict format, ...)
{
	va_list		list;

	va_start(list, format);
	return (ft_doformat(format, list, 0));
}
