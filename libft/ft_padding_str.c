/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_padding_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/03 15:23:56 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 15:56:11 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_padding_str(t_print *select, char *tmp, char c)
{
	int		len;
	char	*buff;

	if (select->prec_turn == 1 && !select->prec)
		tmp = ft_strdup("");
	if (select->prec && (select->prec < ft_strlen(tmp)))
		tmp = ft_strndup(tmp, select->prec);
	len = select->width - ft_strlen(tmp) - select->null;
	if (len > 0)
	{
		buff = ft_strnew(len + 1);
		ft_memset(buff, c, len);
		if (select->flag_minus)
			tmp = ft_strjoin(tmp, buff);
		else
			tmp = ft_strjoin(buff, tmp);
	}
	return (tmp);
}
