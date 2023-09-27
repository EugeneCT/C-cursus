#include "libft.h"
#include <stdio.h>
int ft_lstsize(t_list *lst)
{
    size_t len = 0;
    t_list *ptr;

    ptr = lst;
    if (ptr)
    {
        len++;
        while (ptr->next)
        {
            len++;
            ptr=ptr->next;
        }
        printf(ptr->content);
    }
    return len;
}



void ft_lstadd_front(t_list **lst, t_list *new)
{
   if (lst)
   {
    if (*lst)
        new->next=*lst;
    *lst->next=new;
    }
}

t_list	*ft_lstnew(void *content)
{
	t_list	*ret;

	ret = (t_list *)malloc(sizeof(t_list) * 2);
	if (!ret)
		return (NULL);
	ret->content = content;
	ret->next = NULL;
	return (ret);
}


int main(){

    t_list  *mylist=ft_lstnew("Hello");
    size_t len = ft_lstsize(mylist);
    printf("%d",len);
    // printf(mylist->content);
}