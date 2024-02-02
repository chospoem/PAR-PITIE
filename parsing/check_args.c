/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:05:25 by csaunier          #+#    #+#             */
/*   Updated: 2024/02/02 17:44:45 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	check_args_before(int ac, char **av)
{
	int	i;

	i = 1;
	if (ac == 1)
		exit(EXIT_FAILURE);
	if (ac < 3)
	{
		if (check_quotes(av) == 1)
			error_no_free();
		else
			return (0);
	}
	while (av[i])
	{
		if (check_char(av[i]) == 1)
			error_no_free();
		while (av[i][1] == '-')
			i++;
		if ((ft_isdigit(ft_atoi(av[i]) == 0)) || (ft_is_an_int(av[i]) == 1))
			error_no_free();
		i++;
	}
	return (0);
}

int	check_quotes(char **av)
{
	long int	i;
	char		**str;
	long int	count;

	i = 0;
	count = 0;
	while (av[1][i])
	{
		if (av[1][i] == ' ')
			count++;
		i++;
	}
	if (count == 0)
		exit(EXIT_FAILURE);
	else
		str = ft_split(av[1], ' ');
	if (check_args_before2(ft_strlen(av[1]), str) == 1)
	{
		free_str(str);
		return (1);
	}
	free_str(str);
	return (0);
}

int	check_args_before2(int ac, char **av)
{
	int	i;

	i = 0;
	if (ac == 1)
		return (1);
	while (av[i])
	{
		if (check_char(av[i]) == 1)
			return (1);
		while (av[i][1] == '-')
			i++;
		if ((ft_isdigit(ft_atoi(av[i]) == 0)) || (ft_is_an_int(av[i]) == 1))
			return (1);
		i++;
	}
	return (0);
}

int	check_args_after(t_maillon *stack_a, t_maillon *stack_b)
{
	if (is_a_sorted(stack_a) == 1)
	{
		no_error_free(stack_a, stack_b);
		exit(EXIT_FAILURE);
	}
	if (is_there_dupl(stack_a) == 1)
		return (1);
	else
		return (0);
}
