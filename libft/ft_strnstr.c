/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:34:58 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/30 18:14:08 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;

	if ((*big) == '\0' || len < 1)
		return (NULL);
	i = ft_strlen(little);
	while (len-- >= i)
	{
		if (!ft_strncmp(big++, little, i))
			return ((char*)(big - 1));
	}
	return (NULL);
}
