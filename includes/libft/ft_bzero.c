/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:04:07 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 17:08:00 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned long int	i;
	unsigned char		*p;

	i = 0;
	p = s;
	while (i < n)
	{
		*p = '\0';
		p++;
		i++;
	}
}
/*
int main()
{
    char s[] = "fraise";
    size_t n = 0;
    printf("%s\n", (char *)s);
    ft_bzero(s, n);
    printf("%s\n", (char*)s);
    return (0);
}*/