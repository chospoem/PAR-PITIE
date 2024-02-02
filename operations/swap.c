/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 19:47:49 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/04 11:42:53 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sa(t_maillon **stack_a)
{
	long int	value;

	value = (*stack_a)->value;
	(*stack_a)->value = (*stack_a)->next->value;
	(*stack_a)->next->value = value;
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_maillon **stack_b)
{
	long int	value;

	value = (*stack_b)->value;
	(*stack_b)->value = (*stack_b)->next->value;
	(*stack_b)->next->value = value;
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_maillon **stack_a, t_maillon **stack_b)
{
	sa(stack_a);
	sb(stack_b);
	ft_putstr_fd("ss\n", 1);
}
