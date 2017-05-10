/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 12:59:30 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/28 11:37:30 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*tdst;
	const char	*tsrc;
	int			i;

	i = 0;
	tdst = dst;
	tsrc = src;
	if (dst < src)
		while (len--)
		{
			tdst[i] = tsrc[i];
			i++;
		}
	else
	{
		tsrc = src + (len - 1);
		tdst = dst + (len - 1);
		while (len--)
			*tdst-- = *tsrc--;
	}
	return (dst);
}
