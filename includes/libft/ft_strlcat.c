/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:05:27 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:06:03 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	long unsigned int	i;
	int					j;

	i = 0;
	j = 0;
	if (size < 1)
		return (size + ft_strlen(src));
	while (dst[i] && (i < size))
		i++;
	while (src[j] && ((i + j) < size - 1))
	{
		dst[i + j] = src[j];
		j++;
	}
	if (i < size)
		dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
int main()
{
	char last[] = "fraises";
	size_t r;
	size_t size = 0;
	char buffer[] = "les";
	r = ft_strlcat(buffer,last,size);
    printf("%s\n", buffer);
	printf("Value returned: %li\n",r);
	if( r > size )
		puts("String truncated");
	else
		puts("String was fully copied");
    return (0);
}*/