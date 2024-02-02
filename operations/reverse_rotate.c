/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:09:41 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/03 13:20:47 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_maillon **stack_a)
{
	t_maillon	*tmp;

	tmp = *stack_a;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->back->next = NULL;
	tmp->back = NULL;
	(*stack_a)->back = tmp;
	tmp->next = *stack_a;
	*stack_a = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_maillon **stack_b)
{
	t_maillon	*tmp;

	tmp = *stack_b;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->back->next = NULL;
	tmp->back = NULL;
	(*stack_b)->back = tmp;
	tmp->next = *stack_b;
	*stack_b = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_maillon **stack_a, t_maillon **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putstr_fd("rrr\n", 1);
}
