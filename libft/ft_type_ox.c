/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_type_oOxX.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 12:10:07 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 16:42:47 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*ft_check_sharp(int base, t_print *sel)
{
	char	*tmp;

	tmp = NULL;
	if (sel->flag_sharp && base == 16 && sel->uporlow)
	{
		tmp = ft_strdup("0X");
		sel->flag_sharp = 3;
	}
	else if (sel->flag_sharp && base == 16)
	{
		tmp = ft_strdup("0x");
		sel->flag_sharp = 3;
	}
	else if (sel->flag_sharp && base == 8)
	{
		tmp = ft_strdup("0");
		sel->flag_sharp = 1;
	}
	return (tmp);
}

char		*ft_check_all_unsigned(char *src, int base, t_print *sel)
{
	char	*sharp;
	char	*tmp;

	tmp = src;
	sharp = ft_check_sharp(base, sel);
	if (sel->prec && sel->prec > ft_strlen(src))
		src = ft_put_precision(sel, src);
	if (sel->width && sel->flag_zero)
		src = ft_put_width(sel, src);
	if (sel->flag_sharp && base == 16 && sel->uporlow && !sel->null)
		src = ft_strjoin_clear(&sharp, &src);
	else if (sel->flag_sharp && base == 16 && !sel->null)
		src = ft_strjoin_clear(&sharp, &src);
	else if (sel->flag_sharp && sel->prec <= ft_strlen(tmp) &&
			base == 8 && !sel->null)
		src = ft_strjoin_clear(&sharp, &src);
	if (sel->width)
		src = ft_put_width(sel, src);
	return (src);
}

int			ft_type_ox(va_list list, int *pos, t_print *select, int base)
{
	unsigned long long	buff;
	char				*tmp;

	*pos = *pos + 1;
	if (select->mod)
		buff = ft_change_type_unll(va_arg(list, unsigned long long), select);
	else
		buff = (unsigned int)va_arg(list, unsigned int);
	if (buff == 0 && !select->pointer)
		select->null = 1;
	if (buff == 0 && select->prec_turn == 1 && !select->prec && base != 8)
		tmp = ft_strdup("");
	else if (buff == 0 && select->prec_turn == 1 &&
			!select->prec && !select->flag_sharp && base == 8)
		tmp = ft_strdup("");
	else
		tmp = ft_itoa_base_set(buff, base, select->uporlow, select);
	tmp = ft_check_all_unsigned(tmp, base, select);
	ft_putstr(tmp);
	select->res += ft_strlen(tmp);
	select->uporlow = 0;
	free(tmp);
	return (1);
}

int			ft_type_pointer(va_list list, int *pos, t_print *select, int base)
{
	select->pointer = 2;
	select->mod = 'l';
	select->flag_sharp = 1;
	return (ft_type_ox(list, pos, select, base));
}
