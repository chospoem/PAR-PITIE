/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:06:18 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:07:11 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	unsigned long int	i;

	i = 0;
	if (size < 1)
		return (ft_strlen(src));
	while (src[i] && (i < size - 1))
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (ft_strlen(src));
}
/*
int main()
{
    char string[] = "J'aime les fraises";
    char buffer[19];
    printf("%li\n", ft_strlcpy(buffer, string, 0));
    
    return (0);
}*/