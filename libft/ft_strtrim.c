/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 14:20:36 by voliynik          #+#    #+#             */
/*   Updated: 2016/12/01 12:11:11 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#define TAB(x) ( x == '\t' || x == '\n' || x == ' ')

static	int	ft_crutch(int i, int len, char *dup, char *start)
{
	while (i <= len)
		dup[i++] = *start++;
	return (i);
}

char		*ft_strtrim(char const *s)
{
	char	*dup;
	char	*start;
	int		len;
	char	*end;
	int		i;

	if (!s)
		return (NULL);
	while (TAB(*s))
		s++;
	len = ft_strlen(s);
	start = (char *)s;
	while (*s)
		s++;
	s--;
	while (TAB(*s))
		s--;
	end = (char *)s;
	len -= ft_strlen(end);
	if (!(dup = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	i = 0;
	i = ft_crutch(i, len, dup, start);
	dup[i] = '\0';
	return (dup);
}
