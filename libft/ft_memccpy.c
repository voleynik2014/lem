/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:46:47 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/30 18:18:02 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*mdst;
	const unsigned char	*msrc;
	unsigned char		j;
	size_t				i;

	i = 0;
	j = c;
	mdst = dst;
	msrc = src;
	while (i < n)
	{
		if ((*mdst++ = *msrc++) == j)
			return (mdst);
		i++;
	}
	return (NULL);
}
