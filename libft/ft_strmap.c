/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/25 13:15:37 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/30 17:54:28 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char		*tmp;
	char		*stmp;

	if (s && f)
	{
		tmp = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
		if (!tmp)
			return (NULL);
		stmp = tmp;
		while (*s)
		{
			*stmp = (*f)(*s);
			s++;
			stmp++;
		}
		*stmp = '\0';
		return (tmp);
	}
	return (NULL);
}
