/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_color.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/25 14:58:34 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/01 15:27:20 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_color(const char *format, int *pos)
{
	if ((ft_strncmp(format + (*pos + 1), "RED}", 4)) == 0 &&
			((*pos) += 5))
		ft_putstr("\x1b[31m");
	else if ((ft_strncmp(format + (*pos + 1), "GREEN}", 6)) == 0 &&
			((*pos) += 7))
		ft_putstr("\x1b[32m");
	else if ((ft_strncmp(format + (*pos + 1), "YELLOW}", 7)) == 0 &&
			((*pos) += 8))
		ft_putstr("\x1b[33m");
	else if ((ft_strncmp(format + (*pos + 1), "BLUE}", 5)) == 0 &&
			((*pos) += 6))
		ft_putstr("\x1b[34m");
	else if ((ft_strncmp(format + (*pos + 1), "MAGENTA}", 8)) == 0 &&
			((*pos) += 9))
		ft_putstr("\x1b[35m");
	else if ((ft_strncmp(format + (*pos + 1), "CYAN}", 5)) == 0 &&
			((*pos) += 6))
		ft_putstr("\x1b[36m");
	else if ((ft_strncmp(format + (*pos + 1), "EOC}", 4)) == 0 &&
			((*pos) += 5))
		ft_putstr("\x1b[0m");
}
