/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:26:43 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/30 17:07:57 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*tmp;
	char	*stmp;
	int		i;

	i = 0;
	if (s && f)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!tmp)
			return (NULL);
		stmp = tmp;
		while (s[i])
		{
			stmp[i] = (*f)(i, s[i]);
			i++;
		}
		stmp[i] = '\0';
		return (tmp);
	}
	return (NULL);
}
