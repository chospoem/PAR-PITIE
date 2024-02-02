/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:11:31 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:11:55 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	unsigned long int		i;
	int						j;
	unsigned long int		size_set;

	i = 0;
	j = 0;
	size_set = ft_strlen(little);
	if (little[0] == '\0')
		return ((char *)big);
	if (len == 0)
		return (NULL);
	while (big[i] && i <= (len - size_set))
	{
		if (big[i] == little[j] && ft_strncmp(&big[i], little, size_set) == 0)
			return ((char *)&big[i]);
		i++;
	}
	return (NULL);
}
/*
int main()
{
    char haystack[30] = "aaabcabcd";
	char needle[10] = "aabc";
	//char * empty = (char*)"";
    printf("%s\n", ft_strnstr(haystack, needle, 0));
    return (0);
}*/