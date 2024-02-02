/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:03:22 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:03:49 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
void f(unsigned int i, char *str)
{
    i = i;
    str[0] = 'u';
}*/

void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
	{
		(*f)(i, &s[i]);
		i++;
	}
}
/*
int main()
{
    void (*pf)(unsigned int, char*);
    char *str = calloc(4, sizeof(char));
    str[0] = 'o';
    str[1] = 'u';
    str[2] = 'i';
    pf = &f;
    printf("%s\n", str);
    ft_striteri(str, pf);
    printf("%s\n", str);
    free(str);
    return (0);
}*/