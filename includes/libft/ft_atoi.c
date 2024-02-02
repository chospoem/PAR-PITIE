/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 16:51:20 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/03 13:39:52 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long int	ft_atoi(const char *nptr)
{
	int			i;
	long int	res;
	int			s;

	i = 0;
	res = 0;
	s = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '-')
	{
		s = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] && (ft_isdigit(nptr[i]) == 1))
	{
		res = (res * 10) + (nptr[i] - 48);
		i++;
	}
	return (res * s);
}
/*
int main()
{
    const char *str = "+42";
    printf("%i\n", ft_atoi(str));
    printf("%i\n", atoi(str));
    return (0);
}*/