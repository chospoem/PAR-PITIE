/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 23:33:22 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/05 10:24:05 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ra(t_maillon **stack_a)
{
	t_maillon	*tmp;
	t_maillon	*i;

	tmp = (*stack_a);
	i = (*stack_a);
	while (i->next != NULL)
		i = i->next;
	*stack_a = tmp->next;
	(*stack_a)->back = NULL;
	i->next = tmp;
	tmp->back = i;
	tmp->next = NULL;
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_maillon **stack_b)
{
	t_maillon	*tmp;
	t_maillon	*i;

	tmp = (*stack_b);
	i = (*stack_b);
	while (i->next != NULL)
		i = i->next;
	*stack_b = tmp->next;
	(*stack_b)->back = NULL;
	i->next = tmp;
	tmp->back = i;
	tmp->next = NULL;
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_maillon **stack_a, t_maillon **stack_b)
{
	ra(stack_a);
	rb(stack_b);
	ft_putstr_fd("rr\n", 1);
}
