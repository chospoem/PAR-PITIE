/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_4.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:49:08 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/21 15:02:17 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/push_swap.h"

void	less_than_4(t_maillon **stack_a)
{
	t_maillon	*tmp;

	while (is_biggest_end(stack_a) == 1)
		rra(stack_a);
	tmp = (*stack_a);
	if (tmp->value > tmp->next->value)
		sa(stack_a);
}

int	is_biggest_end(t_maillon **stack_a)
{
	t_maillon	*biggest;
	t_maillon	*tmp;

	biggest = find_biggest((*stack_a));
	tmp = (*stack_a);
	while (tmp->next)
		tmp = tmp->next;
	if (tmp->value == biggest->value)
		return (0);
	return (1);
}

t_maillon	*find_last(t_maillon *stack_a)
{
	t_maillon	*tmp;

	tmp = stack_a;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_maillon	*find_biggest(t_maillon *stack_a)
{
	t_maillon	*tmp;
	t_maillon	*biggest;

	tmp = stack_a->next;
	biggest = stack_a;
	while (tmp != NULL)
	{
		if (biggest->value < tmp->value)
			biggest = tmp;
		tmp = tmp->next;
	}
	return (biggest);
}
