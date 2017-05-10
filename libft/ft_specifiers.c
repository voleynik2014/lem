/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 16:22:20 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 16:10:33 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_flags(const char *format, int *pos, t_print *select)
{
	if (format[*pos + 1] == '-' || format[*pos + 1] == '+' ||
			format[*pos + 1] == ' ' || format[*pos + 1] == '#' ||
			format[*pos + 1] == '0')
	{
		if (format[*pos + 1] == '-')
			select->flag_minus = 1;
		else if (format[*pos + 1] == '+')
			select->flag_plus = 1;
		else if (format[*pos + 1] == ' ')
			select->flag_space = 1;
		else if (format[*pos + 1] == '#')
			select->flag_sharp = 1;
		else if (format[*pos + 1] == '0' && !select->flag_minus)
			select->flag_zero = 1;
		*pos += 1;
		return (1);
	}
	return (0);
}

int		ft_check_width(const char *format, va_list list,
		int *pos, t_print *select)
{
	int		tmp;

	if (format[*pos + 1] == '*')
	{
		*pos += 1;
		if ((tmp = va_arg(list, int)) < 0)
			select->flag_minus = 1;
		select->width = tmp < 0 ? -tmp : tmp;
		return (1);
	}
	else if (ft_isdigit(format[*pos + 1]))
	{
		select->width = 0;
		while (ft_isdigit(format[*pos + 1]))
		{
			select->width = select->width * 10 + format[*pos + 1] - '0';
			*pos += 1;
		}
		return (1);
	}
	return (0);
}

int		ft_check_precision(const char *format, va_list list,
		int *pos, t_print *select)
{
	int		tmp;

	tmp = 0;
	if (format[*pos + 1] == '.' && ++(*pos))
	{
		select->prec_turn = 1;
		select->prec = 0;
		if (format[*pos + 1] == '*')
		{
			*pos += 1;
			if ((tmp = va_arg(list, int)) < 0)
				select->prec = 0;
			else
				select->prec = tmp;
		}
		else if (ft_isdigit(format[*pos + 1]))
		{
			while (ft_isdigit(format[*pos + 1]))
				select->prec = select->prec * 10 + format[++(*pos)] - '0';
		}
		if (tmp >= 0)
			select->flag_zero = 0;
		return (1);
	}
	return (0);
}

int		ft_check_mod(const char *format, int *pos, t_print *select)
{
	if (format[*pos + 1] == 'h' || format[*pos + 1] == 'l' ||
			format[*pos + 1] == 'j' || format[*pos + 1] == 'z')
	{
		if (format[*pos + 1] == 'h')
		{
			if (format[*pos + 2] && format[*pos + 2] == 'h' && ++(*pos))
				select->mod = 'H';
			else
				select->mod = 'h';
		}
		else if (format[*pos + 1] == 'l')
		{
			if (format[*pos + 2] && format[*pos + 2] == 'l' && ++(*pos))
				select->mod = 'L';
			else
				select->mod = 'l';
		}
		else if (format[*pos + 1] == 'j')
			select->mod = 'j';
		else if (format[*pos + 1] == 'z')
			select->mod = 'z';
		*pos += 1;
		return (1);
	}
	return (0);
}

int		ft_check_type(const char *format, va_list list,
		int *pos, t_print *select)
{
	if (format[*pos + 1] == 's')
		return (ft_type_s(list, pos, select));
	else if (format[*pos + 1] == 'd' || format[*pos + 1] == 'i')
		return (ft_type_di(list, pos, select));
	else if (format[*pos + 1] == 'D' && (select->mod = 'l'))
		return (ft_type_di(list, pos, select));
	else if (format[*pos + 1] == 'u')
		return (ft_type_u(list, pos, select));
	else if (format[*pos + 1] == 'U' && (select->mod = 'l'))
		return (ft_type_ox(list, pos, select, 10));
	else if (format[*pos + 1] == 'c')
		return (ft_type_c(list, pos, select, 0));
	else if (format[*pos + 1] == 'o')
		return (ft_type_ox(list, pos, select, 8));
	else if (format[*pos + 1] == 'O' && (select->mod = 'L'))
		return (ft_type_ox(list, pos, select, 8));
	else
		return (ft_check_type_2(format, list, pos, select));
}
