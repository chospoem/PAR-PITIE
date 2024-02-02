/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:30:13 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:02:12 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char			*ptr;
	int				i;
	unsigned char	d;

	i = 0;
	ptr = (char *)s;
	d = (unsigned char)c;
	while (s[i])
	{
		if (s[i] == d)
			return (ptr);
		ptr++;
		i++;
	}
	if (d == 0 && s[i] == '\0')
		return (ptr);
	return (NULL);
}
/*
int main()
{
    const char *str = "fraises";
    //int c = 'a';
    printf("%s\n", ft_strchr(str, 'f'));
    return (0);
}*/