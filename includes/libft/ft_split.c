/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 18:04:29 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 19:39:37 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	countwords(const char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	if (str[0] == '\0')
		return (0);
	if (str[0] != c)
		count = 1;
	while (str[i])
	{
		if (str[i] == c && str[i + 1] != c)
			count++;
		i++;
	}
	if (str[i - 1] == c)
		count--;
	return (count);
}

static size_t	wordsize(const char *str, char sep, int start)
{
	size_t	count;

	count = 0;
	while (str[start] && str[start] != sep)
	{
		count++;
		start++;
	}
	return (count);
}

static unsigned int	ft_start(const char *str, char c, unsigned int start, int i)
{
	if (str[0] == '\0')
		return (0);
	if (i == 0 && start == 0 && str[start] != c)
		return (0);
	while (str[start] && str[start] != c)
		start++;
	while (str[start] && str[start] == c)
		start++;
	return (start);
}

static char	**ft_fillstrs(char **str, const char *s, char c)
{
	int				j;
	int				count;
	unsigned int	start;

	j = 0;
	count = 0;
	start = 0;
	while (j < countwords(s, c))
	{
		start = ft_start(s, c, start, count);
		count++;
		str[j] = ft_substr(s, start, wordsize(s, c, start));
		if (str[j] == NULL)
		{
			while (j > 0)
			{
				free(str[j]);
				j--;
			}
			return (NULL);
		}
		j++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	char			**str;

	if (s == NULL)
		return (NULL);
	str = malloc(sizeof(char *) * ((countwords(s, c)) + 1));
	if (str == NULL)
		return (NULL);
	str = ft_fillstrs(str, s, c);
	if (str == NULL)
		return (NULL);
	str[countwords(s, c)] = NULL;
	return (str);
}
/*
int main()
{
    int i;
    const char *str = "split  ||this|for|me|||||!|";
    char **str1;
    char c = '|';
    str1 = ft_split(str, c);
    i = 0;
    while (str1[i])
    {
        printf("%s\n", str1[i]);
        free(str1[i]);
        i++;
    }
    free(str1);
    return (0);
}*/