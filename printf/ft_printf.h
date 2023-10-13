/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:10:32 by cliew             #+#    #+#             */
/*   Updated: 2023/10/13 13:38:30 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "libft/libft.h"
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
int		ft_printf(const char *str, ...);
int		put_formatted_args(int flags[][5], va_list *argv);
int		form_dict(char **str, int flags[][5]);

int		specifier_c(int flags[][5], int arg);
int		specifier_s(int flags[][5], char *arg);
int		specifier_p(int flags[][5], void *arg);
int		specifier_d(int flags[][5], int arg);
int		specifier_i(int flags[][5], int arg);
int		specifier_u(int flags[][5], unsigned int arg);
int		specifier_x(int flags[][5], int arg);
int		specifier_bigx(int flags[][5], int arg);

void	ft_dectohex(unsigned long long number, char *base);
void	ft_putstr(char *str,int len);
void	ft_putint(int number);
void	ft_putuint(unsigned int number);

int		check_flags(char **str, int flags[][5]);
int		check_min_width(char **str, int flags[][5]);
int		check_precision(char **str, int flags[][5]);
int		check_specifier(char **str, int flags[][5]);



#endif