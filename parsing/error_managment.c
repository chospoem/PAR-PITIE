/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_managment.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:09:02 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/31 15:57:47 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	error_no_free(void)
{
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	error_free(t_maillon *stack_a, t_maillon *stack_b)
{
	free_stack(stack_a);
	free_stack(stack_b);
	ft_putstr_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}

void	no_error_free(t_maillon *stack_a, t_maillon *stack_b)
{
	free_stack(stack_a);
	if (stack_b == NULL)
		free(stack_b);
	else
		free_stack(stack_b);
}

void	free_stack(t_maillon *stack)
{
	t_maillon	*tmp;

	tmp = NULL;
	while (stack != NULL)
	{
		tmp = stack->next;
		free(stack);
		stack = tmp;
	}
	if (tmp != NULL)
		free(tmp);
}

void	free_str(char **str)
{
	long int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
