/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/11 18:58:27 by voliynik          #+#    #+#             */
/*   Updated: 2017/01/21 17:50:39 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include "libft.h"
# include <fcntl.h>
# define BUFF_SIZE 10

typedef	struct		s_get
{
	int				fd;
	char			*buffer;
	struct s_get	*next;
}					t_get;

int					get_next_line(const int fd, char **line);

#endif
