/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:46:50 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 17:47:35 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned const char	*s;
	unsigned char		*d;
	long int			i;

	s = src;
	d = dest;
	i = n - 1;
	if (d > s)
	{
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		ft_memcpy(d, s, n);
	return (dest);
}
/*
int main()
{
    char dest[] = "aaaaaaaaaaaaa";
    const void *src = "fraises";
    size_t n = 0;
    printf("%s\n", (char*)ft_memmove(dest, src, n));
    return (0);
}*/