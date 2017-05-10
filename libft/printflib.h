/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printflib.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: voliynik <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/01 13:55:10 by voliynik          #+#    #+#             */
/*   Updated: 2017/03/17 18:44:07 by voliynik         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTFLIB_H
# define PRINTFLIB_H

# include "ft_printf.h"

typedef struct		s_print
{
	int				flag_plus;
	int				flag_minus;
	int				flag_zero;
	int				flag_space;
	int				flag_sharp;
	int				pos;
	int				res;
	size_t			width;
	int				uporlow;
	size_t			prec;
	int				prec_turn;
	size_t			res_minus;
	char			mod;
	int				null;
	int				pointer;
	size_t			set;
	int				toggle;
}					t_print;

int					ft_putnstr(char const *src, int len);
char				*ft_padding(t_print *select, char *tmp, char c, int len);
char				*ft_put_width(t_print *sel, char *tmp);
char				*ft_put_precision(t_print *sel, char *tmp);

char				*ft_padding_str(t_print *select, char *tmp, char c);
char				*ft_strjoin_clear(char **s1, char **s2);
char				*ft_put_str_str(char *src, int len, char c, t_print *sel);

char				*ft_check_all(long long buff, char *tmp, t_print *select);
char				*ft_check_all_unsigned(char *src, int base,
					t_print *select);
void				ft_put_uintmax(uintmax_t n);
char				*ft_uintmax_toa(uintmax_t n);
char				*ft_itoa_base_set(unsigned long long n,
					size_t set, char toggle, t_print *sel);
char				*ft_itoa_ll(long long n);
unsigned long long	ft_change_type_unll(unsigned long long buff,
					t_print *select);

char				*ft_strndup(const char *src, size_t len);

void				ft_putwchar(wchar_t chr);
int					ft_wchar(va_list list, int *pos, t_print *select);
void				ft_padding_wstr(t_print *select, wchar_t *tmp, char c);
void				ft_putwstr(wchar_t *tmp);
size_t				ft_wstrlen(wchar_t *str);
size_t				ft_wcharlen(wchar_t c);

void				ft_bzero_struct(t_print *sel);

#endif
