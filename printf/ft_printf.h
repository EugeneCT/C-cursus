/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:10:32 by cliew             #+#    #+#             */
/*   Updated: 2023/10/09 17:13:44 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include "libft/libft.h"

int specifier_c(int flags[][5],int arg,int *output);
int specifier_s(int flags[][5],char *arg, int *output);
int specifier_p(int flags[][5],void *arg,int *output);
int specifier_d(int flags[][5],int arg,int *output);
int specifier_i(int flags[][5],int arg,int *output);
int specifier_u(int flags[][5],unsigned int arg,int *output);
int specifier_x(int flags[][5],int arg,int *output);
int specifier_X(int flags[][5],int arg,int *output);

void	ft_dectohex(unsigned long long number, char *base, int *output);
void	ft_putstr(char *str, int *output);
void	ft_putint(int number, int *output);
void	ft_putuint(unsigned int number, int *output);

int	check_flags(char **str, int flags[][5]);
int	check_min_width(char **str, int flags[][5]);
int	check_precision(char **str, int flags[][5]);
int	check_specifier(char **str, int flags[][5]);

#endif