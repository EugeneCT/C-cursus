/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/24 09:57:16 by cliew             #+#    #+#             */
/*   Updated: 2023/09/24 09:57:16 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
// #include <stdio.h>

t_list *ft_lstnew(void *content){

   
    t_list *ret;

    ret = (t_list *)malloc(sizeof(t_list) * 2 );
    ret->content = content;
    ret->next=NULL;
    return (ret->next);



}

int main()
{
    t_list* get;

    get= ft_lstnew("hello");
    printf(:get);
}
