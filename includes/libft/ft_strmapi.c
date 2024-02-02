/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:07:50 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:09:31 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
char f(unsigned int n, char c)
{
    n = n;
    c = 'o';
    return (c);
}*/

static char	*ft_strcpy(char *dest, const char *src)
{
	unsigned long int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*dest;

	if (s == NULL)
		return (NULL);
	i = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (dest == NULL || s == NULL)
		return (NULL);
	ft_strcpy(dest, s);
	while (dest[i])
	{
		dest[i] = (*f)(i, dest[i]);
		i++;
	}
	return (dest);
}
/*
int main()
{
    char (*pf)(unsigned int, char);
    char const *s = "non";
    pf = &f;
    char *dest = ft_strmapi(s, pf);
    printf("%s\n", dest);
    free(dest);
    return (0);
}*/