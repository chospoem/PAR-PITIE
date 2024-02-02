/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:46:03 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 17:46:38 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned long int	i;
	unsigned char		*p;
	unsigned char		*s;

	i = 0;
	p = dest;
	s = (unsigned char *)src;
	if (src == NULL && dest == NULL)
		return (dest);
	while (i < n)
	{
		*p = *s;
		p++;
		s++;
		i++;
	}
	return (dest);
}
/*
int main()
{
    const void *src = "fraises";
    size_t n = 5;
    char dest[5];
    printf("%s\n", (char*)ft_memcpy(dest, src, n));
    return (0);
}*/