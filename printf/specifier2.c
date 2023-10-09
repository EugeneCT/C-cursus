/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   specifier2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/09 17:03:57 by cliew             #+#    #+#             */
/*   Updated: 2023/10/09 17:05:30 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
int specifier_c(int flags[][5],int arg,int *output){

	output+= write(1, &arg, 1);
	flags[0][0]=1;
	return (1);
	
}



int specifier_s(int flags[][5],char *arg, int *output){
	flags[0][0]=1;

	ft_putstr(arg,(output));
	return (1);

}


int specifier_x(int flags[][5],int arg,int *output){
	flags[0][0]=1;

	if (!arg)
		*output += write(1, "(nil)", 5);
	ft_dectohex(arg,"0123456789abcdef",output);
	return (1);

	
}


int specifier_X(int flags[][5],int arg,int *output){
	flags[0][0]=1;

	if (!arg)
		*output += write(1, "(nil)", 5);
	ft_dectohex(arg,"0123456789ABCDEF",output);
	return (1);

	
}
