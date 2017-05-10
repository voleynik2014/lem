/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 11:45:22 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/17 18:57:38 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strjoin_clear(char **s1, char **s2)
{
	char	*res;

	res = ft_strjoin(*s1, *s2);
	ft_strdel(s1);
	ft_strdel(s2);
	return (res);
}

char	*ft_put_str_str(char *src, int len, char c, t_print *sel)
{
	char	*buff;

	buff = ft_strnew(len + 1);
	ft_memset(buff, c, len);
	if (sel->flag_minus && c != '0')
		src = ft_strjoin_clear(&src, &buff);
	else
		src = ft_strjoin_clear(&buff, &src);
	return (src);
}

char	*ft_put_width(t_print *sel, char *tmp)
{
	int		len;

	len = sel->width - ft_strlen(tmp);
	if (len > 0 && sel->flag_zero)
	{
		if (sel->flag_sharp)
			sel->flag_sharp -= 1;
		len = sel->width - ft_strlen(tmp) - sel->flag_sharp
			- (sel->res_minus || sel->flag_plus ? +1 : 0);
		tmp = ft_put_str_str(tmp, len, '0', sel);
	}
	else if (len > 0)
		tmp = ft_put_str_str(tmp, len, ' ', sel);
	return (tmp);
}

char	*ft_put_precision(t_print *sel, char *tmp)
{
	int		len;

	len = sel->prec - ft_strlen(tmp);
	if (sel->prec > ft_strlen(tmp))
		return (ft_put_str_str(tmp, len, '0', sel));
	return (tmp);
}
