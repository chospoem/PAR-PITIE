/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 20:59:05 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/18 15:47:14 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_stack_empty(t_maillon *stack)
{
	if (stack == NULL)
		return (1);
	else
		return (0);
}

void	pa(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*tmp;

	if (is_stack_empty(*stack_b) == 1)
		return ;
	else if (*stack_a == NULL)
		first_in_a(stack_a, stack_b);
	else if (get_stack_size((*stack_b)) < 2)
		last_in_b(stack_a, stack_b);
	else
	{
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		(*stack_b)->back = NULL;
		tmp->next = *stack_a;
		(*stack_a)->back = tmp;
		*stack_a = tmp;
	}
	ft_putstr_fd("pa\n", 1);
}

void	first_in_a(t_maillon **stack_a, t_maillon **stack_b)
{
	*stack_a = *stack_b;
	*stack_b = (*stack_b)->next;
	(*stack_b)->back = NULL;
	(*stack_a)->next = NULL;
	(*stack_a)->back = NULL;
}

void	last_in_b(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*tmp;

	tmp = (*stack_b);
	(*stack_b) = NULL;
	tmp->next = (*stack_a);
	(*stack_a)->back = tmp;
	(*stack_a) = tmp;
}
