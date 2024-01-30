/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew < cliew@student.42singapore.sg>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:10:32 by cliew             #+#    #+#             */
/*   Updated: 2024/01/30 17:27:36 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *str, ...);
void	ft_putstr(char *str, int *count);
void	ft_putint(int number, int *count);
void	ft_putuint(unsigned int number, int *count);
void	ft_puthex(void *ptr, int *count);
void	ft_dectohex(unsigned int number, char *base, int *count);
void	ft_ulltohex(unsigned long long number, char *base, int *count);
int		ft_printf(const char *str, ...);

char	*ft_itoa(int n);
#endif
