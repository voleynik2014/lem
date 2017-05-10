/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_s.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:23:12 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 16:57:44 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_type_s(va_list list, int *pos, t_print *select)
{
	char	*tmp;
	char	*dup;

	if (select->mod == 'l')
		return (ft_type_wchar(list, pos, select));
	*pos = *pos + 1;
	tmp = (va_arg(list, char *));
	if (tmp == NULL)
		dup = ft_strdup("(null)");
	else
		dup = ft_strdup(tmp);
	if (select->width || select->prec)
		dup = ft_padding_str(select, dup, ' ');
	ft_putstr(dup);
	select->res += ft_strlen(dup);
	free(dup);
	return (1);
}

int		ft_type_c(va_list list, int *pos, t_print *select, int flag)
{
	char	*tmp;
	int		i;

	i = 0;
	if (select->mod == 'l' && !flag)
		return (ft_wchar(list, pos, select));
	tmp = ft_strnew(2);
	if (!flag && ++(*pos))
		tmp[0] = (char)va_arg(list, int);
	else if (flag)
		tmp[0] = flag;
	if (tmp[0] == 0 && ++select->res)
		select->null = 1;
	if (select->width || select->prec)
		tmp = ft_padding_str(select, tmp, ' ');
	select->res += ft_strlen(tmp);
	ft_putstr(tmp);
	free(tmp);
	return (1);
}
