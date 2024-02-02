/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:38:22 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/18 15:47:38 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	pb(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*tmp;

	if (is_stack_empty(*stack_a) == 1)
		return ;
	if (get_stack_size((*stack_a)) < 2)
	{
		last_in_a(stack_a, stack_b);
		ft_putstr_fd("pb\n", 1);
		return ;
	}
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	(*stack_a)->back = NULL;
	tmp->next = *stack_b;
	(*stack_b)->back = tmp;
	*stack_b = tmp;
	ft_putstr_fd("pb\n", 1);
}

void	first_in_b(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*tmp;

	tmp = (*stack_a);
	*stack_a = (*stack_a)->next;
	(*stack_a)->back = NULL;
	(*stack_b)->value = tmp->value;
	free(tmp);
	ft_putstr_fd("pb\n", 1);
}

void	last_in_a(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*tmp;

	tmp = (*stack_a);
	(*stack_a) = NULL;
	tmp->next = (*stack_b);
	(*stack_b)->back = tmp;
	(*stack_b) = tmp;
}
