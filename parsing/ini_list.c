/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ini_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:05:18 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/18 16:16:37 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_maillon	*ini_stack_a(int ac, char **av)
{
	char		**str;
	t_maillon	*stack_a;

	if (ac < 3)
	{
		str = ft_split(av[1], ' ');
		if (str == NULL)
			error_no_free();
		stack_a = ft_lstnewm((void *)ft_atoi(str[0]));
		free_str(str);
	}
	else
		stack_a = ft_lstnewm((void *)ft_atoi(av[1]));
	return (stack_a);
}

t_maillon	*ft_lstnewm(void *content)
{
	t_maillon	*new;

	new = malloc(sizeof(t_maillon));
	if (new == NULL)
		return (NULL);
	new->value = (long int)content;
	new->back = NULL;
	new->next = NULL;
	return (new);
}

int	fill_stack_a(int ac, char **av, t_maillon *stack_a)
{
	int		i;

	i = 2;
	if (ac < 3)
	{
		if (fill_quotes(av, stack_a) == 1)
			return (1);
	}
	else
	{
		while (av[i])
		{
			if (push_back_new(stack_a, ft_atoi(av[i])) == 1)
				return (1);
			i++;
		}
	}
	return (0);
}

int	fill_quotes(char **av, t_maillon *stack_a)
{
	int		i;
	char	**str;

	i = 1;
	str = ft_split(av[1], ' ');
	if (str == NULL)
		error_no_free();
	while (str[i])
	{
		if (push_back_new(stack_a, ft_atoi(str[i])) == 1)
		{
			free_str(str);
			return (1);
		}
		i++;
	}
	free_str(str);
	return (0);
}

int	push_back_new(t_maillon *stack_a, long int x)
{
	t_maillon	*new;
	t_maillon	*tmp;

	tmp = stack_a;
	new = malloc(sizeof(t_maillon));
	if (new == NULL)
		return (1);
	new->value = x;
	new->next = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->back = tmp;
	return (0);
}
