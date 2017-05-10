/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifiers2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:41:18 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 16:10:55 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_check_type_2(const char *format, va_list list,
		int *pos, t_print *select)
{
	if (format[*pos + 1] == 'x')
		return (ft_type_ox(list, pos, select, 16));
	else if (format[*pos + 1] == 'X' && (select->uporlow = 'A'))
		return (ft_type_ox(list, pos, select, 16));
	else if (format[*pos + 1] == 'p')
		return (ft_type_pointer(list, pos, select, 16));
	else if (format[*pos + 1] == 'C')
		return (ft_wchar(list, pos, select));
	else if (format[*pos + 1] == 'S')
		return (ft_type_wchar(list, pos, select));
	return (0);
}

void	ft_bzero_struct(t_print *sel)
{
	sel->flag_plus = 0;
	sel->flag_minus = 0;
	sel->flag_zero = 0;
	sel->flag_space = 0;
	sel->flag_sharp = 0;
	sel->width = 0;
	sel->uporlow = 0;
	sel->prec = 0;
	sel->prec_turn = 0;
	sel->res_minus = 0;
	sel->mod = 0;
	sel->null = 0;
	sel->pointer = 0;
	sel->null = 0;
	sel->set = 0;
	sel->toggle = 0;
}
