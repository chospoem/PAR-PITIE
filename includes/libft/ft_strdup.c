/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:02:30 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:03:07 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	unsigned long int	size;
	unsigned long int	i;
	char				*dest;

	size = ft_strlen(s);
	i = 0;
	dest = malloc(sizeof(char) * (size + 1));
	if (dest == NULL)
		return (NULL);
	while (s[i])
	{
		dest[i] = s[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
/*
int main()
{
    const char *s = "";
    char *dest = ft_strdup(s);
    printf("%s\n", dest);
    free(dest);
    return (0);
}*/