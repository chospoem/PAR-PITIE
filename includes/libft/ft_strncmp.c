/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:09:39 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:10:32 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned long int	i;
	unsigned char		*ptr1;
	unsigned char		*ptr2;

	ptr1 = (unsigned char *)s1;
	ptr2 = (unsigned char *)s2;
	i = 0;
	while ((*ptr1 || *ptr2) && (i < n))
	{
		if (*ptr1 != *ptr2)
			return (*ptr1 - *ptr2);
		ptr1++;
		ptr2++;
		i++;
	}
	return (0);
}
/*
int main()
{
    const char *s1 = "ZBA";
    const char *s2 = "ABA";
    size_t n = 0;
    printf("%i\n", ft_strncmp(s1, s2, n));
    return (0);
}*/