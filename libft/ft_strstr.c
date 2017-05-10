/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 17:21:45 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/30 18:13:33 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *big, const char *little)
{
	int	i;
	int	j;
	int	count;

	count = 0;
	j = 0;
	i = ft_strlen(little);
	if (i == 0)
		return ((char *)big);
	while (big[j])
	{
		while (big[count + j] == little[count])
		{
			if (count == i - 1)
				return ((char *)big + j);
			count++;
		}
		count = 0;
		j++;
	}
	return (NULL);
}
