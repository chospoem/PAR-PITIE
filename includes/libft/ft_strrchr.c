/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:12:00 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:12:47 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char			*ptr;
	int				i;
	unsigned char	d;

	i = ft_strlen(s);
	ptr = (char *)s;
	d = (unsigned char)c;
	while (i >= 0)
	{
		if (s[i] == d)
			return (ptr + i);
		i--;
	}
	return (NULL);
}
/*
int main()
{
    const char *str = "fraises";
    //int c = 's';
    printf("%s\n", ft_strrchr(str, 'f' + 256));
    return (0);
}*/