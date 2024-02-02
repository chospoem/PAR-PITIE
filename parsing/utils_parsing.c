/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:55:03 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/21 15:01:58 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_char(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == '-')
			i++;
		if (av[i] < 48 || av[i] > 57)
			return (1);
		i++;
	}
	return (0);
}

int	ft_is_an_int(char *av)
{
	long int	value;

	value = ft_atoi(av);
	if (value > 2147483647 || value < -2147483648)
		return (1);
	else
		return (0);
}

int	is_a_sorted(t_maillon *stack_a)
{
	t_maillon	*tmp;

	tmp = stack_a;
	while (tmp->next != NULL)
	{
		if (tmp->value > tmp->next->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	is_there_dupl(t_maillon *stack_a)
{
	t_maillon	*tmp1;
	t_maillon	*tmp2;

	tmp1 = stack_a;
	tmp2 = tmp1->next;
	while (tmp1->next != NULL)
	{
		while (tmp2 != NULL)
		{
			if (tmp1->value == tmp2->value)
				return (1);
			tmp2 = tmp2->next;
		}
		tmp1 = tmp1->next;
		tmp2 = tmp1->next;
	}
	return (0);
}
