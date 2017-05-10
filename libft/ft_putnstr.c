/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:42:27 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 14:57:38 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_putnstr(char	const *src, int len)
{
	int i;

	i = 0;
	if (src)
		while (src[i] && i < len)
			ft_putchar(src[i++]);
	return (len);
}
