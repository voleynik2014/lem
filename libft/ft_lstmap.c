/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/30 17:36:25 by voliynik          #+#    #+#             */
/*   Updated: 2016/11/30 17:36:26 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *ret;
	t_list *newlst;
	t_list *carriage;

	if (!lst || !f)
		return (NULL);
	newlst = (*f)(lst);
	if (!newlst)
		return (NULL);
	ret = newlst;
	carriage = lst->next;
	while (carriage)
	{
		newlst->next = (*f)(carriage);
		newlst = newlst->next;
		if (!newlst)
			return (NULL);
		carriage = carriage->next;
	}
	return (ret);
}
