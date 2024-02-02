/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 19:12:56 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:15:29 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	isset(const char c, const char *set)
{
	int					i;
	unsigned long int	count;

	i = 0;
	count = 0;
	while (set[i])
	{
		if (set[i] != c)
			count++;
		i++;
	}
	if (count == ft_strlen(set))
		return (0);
	return (1);
}

static int	isfirstset(const char *str, const char *set)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (isset(str[i], set) == 0)
			return (i);
		i++;
	}
	return (i);
}

static unsigned long int	islastset(const char *str, const char *set)
{
	unsigned long int	i;
	unsigned long int	count;

	i = ft_strlen(str);
	count = 0;
	while (i--)
	{
		if (isset(str[i], set) == 0)
			return (count);
		count++;
	}
	return (ft_strlen(str));
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char			*dest;
	unsigned int	start;
	size_t			len;

	if (s1 == NULL || set == NULL)
		return (NULL);
	start = isfirstset(s1, set);
	len = ft_strlen(s1) - start - islastset(s1, set);
	if (start + islastset(s1, set) >= ft_strlen(s1))
		return (ft_strdup(""));
	dest = ft_substr(s1, start, len);
	if (dest == NULL)
		return (NULL);
	return (dest);
}

/*
int main()
{
    //char const *str = "lesfraisesles";
    //char const *set = "s";
    char *dest;
    dest = ft_strtrim("abcdba", "acb");
    printf("%s\n", dest);
    printf("%li\n", ft_strlen(dest));
    free(dest);
    return (0);
}*/