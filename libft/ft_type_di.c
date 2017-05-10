/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_di.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 19:20:14 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 17:12:30 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long long			ft_change_type(long long buff, t_print *select)
{
	if (select->mod == 'h')
		return ((short)buff);
	else if (select->mod == 'H')
		return ((char)buff);
	else if (select->mod == 'l')
		return ((long)buff);
	else if (select->mod == 'L')
		return ((long long)buff);
	else if (select->mod == 'j')
		return ((intmax_t)buff);
	else if (select->mod == 'z')
		return ((ssize_t)buff);
	else
		return ((int)buff);
}

unsigned long long	ft_change_type_unll(unsigned long long buff,
		t_print *select)
{
	if (select->mod == 'h')
		return ((unsigned short)buff);
	if (select->mod == 'H')
		return ((unsigned char)buff);
	if (select->mod == 'l')
		return ((unsigned long)buff);
	if (select->mod == 'L')
		return ((unsigned long long)buff);
	if (select->mod == 'j')
		return ((uintmax_t)buff);
	if (select->mod == 'z')
		return ((ssize_t)buff);
	else
		return ((unsigned int)buff);
}

char				*ft_check_all(long long buff, char *tmp,
		t_print *select)
{
	select->flag_sharp = 0;
	if (select->prec && select->prec > ft_strlen(tmp))
		tmp = ft_put_precision(select, tmp);
	if (select->width && select->flag_zero)
		tmp = ft_put_width(select, tmp);
	if (select->flag_plus && buff >= 0)
		tmp = ft_strjoin("+", tmp);
	else if (select->res_minus)
		tmp = ft_strjoin("-", tmp);
	if (select->width)
		tmp = ft_put_width(select, tmp);
	else if (select->flag_space && buff >= 0 &&
			!select->flag_plus && (select->res += 1))
		ft_putchar(' ');
	return (tmp);
}

int					ft_type_di(va_list list, int *pos, t_print *select)
{
	long long		buff;
	char			*tmp;

	*pos = *pos + 1;
	if (select->mod)
		buff = (long long)ft_change_type(va_arg(list, long long int), select);
	else
		buff = (int)va_arg(list, int);
	if (buff < 0)
		select->res_minus = 1;
	if (buff == 0)
		select->null = 1;
	if (buff == 0 && select->prec_turn == 1 && !select->prec)
		tmp = ft_strdup("");
	else
		tmp = ft_itoa_ll(buff);
	tmp = ft_check_all(buff, tmp, select);
	ft_putstr(tmp);
	select->res = select->res + ft_strlen(tmp);
	free(tmp);
	return (1);
}

int					ft_type_u(va_list list, int *pos, t_print *select)
{
	long long	buff;
	char		*tmp;

	*pos = *pos + 1;
	if (select->mod)
		buff = ft_change_type_unll(va_arg(list, long long), select);
	else
		buff = (unsigned int)va_arg(list, unsigned int);
	if (buff == 0)
		select->null = 1;
	if (buff == 0 && select->prec_turn == 1 && !select->prec)
		tmp = ft_strdup("");
	else
		tmp = ft_itoa_base_set(buff, 10, 0, select);
	tmp = ft_check_all_unsigned(tmp, 0, select);
	ft_putstr(tmp);
	select->res = select->res + ft_strlen(tmp);
	free(tmp);
	return (1);
}
