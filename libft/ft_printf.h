/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/26 15:44:41 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/25 16:00:24 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <wchar.h>
# include <stdlib.h>
# include "libft.h"
# include "printflib.h"

# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define EOC   "\x1b[0m"

int		ft_printf(const char *restrict format, ...);
int		ft_doformat(const char *restrict format, va_list ap, int pos);

int		ft_check_specifiers(const char *format, va_list list,
		int *pos, t_print *select);

int		ft_check_flags(const char *format, int *pos, t_print *select);
int		ft_check_width(const char *format, va_list list,
		int *pos, t_print *select);
int		ft_check_precision(const char *format,
		va_list list, int *pos, t_print *select);
int		ft_check_mod(const char *format, int *pos, t_print *select);
int		ft_check_type(const char *format, va_list list,
		int *pos, t_print *select);
int		ft_check_type_2(const char *format,
		va_list list, int *pos, t_print *select);
int		ft_type_pointer(va_list list, int *pos, t_print *select, int base);

int		ft_type_s(va_list list, int *pos, t_print *select);
int		ft_type_di(va_list list, int *pos, t_print *select);
int		ft_type_c(va_list list, int *pos, t_print *select, int flag);
int		ft_type_u(va_list list, int *pos, t_print *select);
int		ft_type_ox(va_list list, int *pos, t_print *select, int base);
int		ft_type_wchar(va_list list, int *pos, t_print *select);

void	ft_color(const char *format, int *pos);

#endif
