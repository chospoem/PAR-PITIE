/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 17:25:03 by csaunier          #+#    #+#             */
/*   Updated: 2023/03/28 17:32:23 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	strsize(long int n)
{
	int	size;

	size = 0;
	if (n < 0)
	{
		size++;
		n *= -1;
	}
	if (n == 0)
		size = 1;
	if (n > 0)
	{
		while (n >= 1)
		{
			n = n / 10;
			size++;
		}
	}
	return (size);
}

static char	*addnbr(long int nbr, int size, char *dest)
{
	int	i;

	i = 0;
	if (nbr < 0)
	{
		dest[i] = '-';
		nbr *= -1;
		i++;
	}
	if (nbr == 0)
	{
		dest[i] = 48;
		i++;
	}
	if (nbr > 0)
	{
		while (i < size)
		{
			dest[i] = (nbr % 10) + 48;
			nbr /= 10;
			i++;
		}
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_itoa(int n)
{
	long int	nbr;
	char		*dest;
	int			i;
	int			tmp;
	char		tmp2;

	nbr = n;
	tmp = (strsize(nbr)) - 1;
	i = 0;
	dest = malloc(sizeof(char) * (strsize(nbr)) + 1);
	if (dest == NULL)
		return (NULL);
	dest = addnbr(nbr, strsize(nbr), dest);
	if (nbr < 0)
		i = 1;
	while (i < tmp)
	{
		tmp2 = dest[i];
		dest[i] = dest[tmp];
		dest[tmp] = tmp2;
		i++;
		tmp--;
	}
	return (dest);
}
/*
int main()
{
    char *str;

    str = ft_itoa(-2147483648);
    printf("%s\n", str);
    free(str);
    return(0);
}*/