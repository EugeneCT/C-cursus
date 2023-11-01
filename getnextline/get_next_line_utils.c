/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cliew <cliew@student.42singapore.sg>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 09:27:41 by cliew             #+#    #+#             */
/*   Updated: 2023/11/01 13:27:29 by cliew            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*res;
	size_t	n;
	size_t	i;

	n = nmemb * size;
	res = malloc(n);
	if (res)
	{
		i = 0;
		while (i < n)
		{
			((unsigned char *)res)[i] = 0;
			i++;
		}
	}
	return (res);
}

void	ft_free(char **s1, char **s2, char **s3)
{
	if (s1 && *s1)
	{
		free(*s1);
		*s1 = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (0);
	i = 0;
	while (s1[i])
		i++;
	j = 0;
	while (s2[j])
		j++;
	res = ft_calloc(i + j + 1, 1);
	if (!res)
		return (NULL);
	i = -1;
	j = -1;
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	return (res);
}

char	*ft_strdup(char *s)
{
	char	*res;
	int		i;

	if (!s)
		return (ft_strdup(""));
	i = 0;
	while (s[i])
		i++;
	res = ft_calloc(i + 1, 1);
	if (!res)
		return (NULL);
	i = 0;
	while (s[i])
	{
		res[i] = s[i];
		i++;
	}
	return (res);
}

char	*ft_strncpy(char *src, size_t n)
{
	size_t	i;
    char *dest;

    dest = (char *)ft_calloc(n+1,1);
	i = 0;
	while (src[i] != '\0' && i < n)
	{
		dest[i] = src[i];
		++i;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

int	ft_strchr(char *str, int chr,int nl_num,int total_nl)
{
	int i;
    int nl_count;
    int start;
    int end;
    char *ret;

	i = 0;
    nl_count=0;
    end =0;
    start =0;
	printf("str=%s\n",str);

	printf("nlnum=%d\n",nl_num);
	printf("tonum=%d\n",total_nl);

	while (str[i] != '\0')
	{
		if (str[i] == chr)
		{
            nl_count++;
            if (nl_num==total_nl && nl_num!=0)
                start=i+1;
                
            if (total_nl+nl_count==nl_num+1)
                end=i;
        }
        if (str[i+1]=='\0')
            end=i;
		i++;
	}
    // ret=ft_strncpy(str+start,end-start);
	printf("%d",start);
	printf("%d",end);

	str=ft_strncpy(str+start,end-start);
	
	return (nl_count);
}

int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

