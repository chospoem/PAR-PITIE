/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   less_than_6.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/07 14:53:23 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/18 15:48:38 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	less_than_6(t_maillon **stack_a, t_maillon **stack_b)
{
	first_in_b(stack_a, stack_b);
	if (get_stack_size(*stack_a) == 4)
		pb(stack_a, stack_b);
	less_than_4(stack_a);
	push_back_5(stack_a, stack_b);
	if (get_index_a(stack_a, is_smallest(*stack_a)) == 1)
	{
		while (is_a_sorted(*stack_a) == 0)
			ra(stack_a);
	}
	else
	{
		while (is_a_sorted(*stack_a) == 0)
			rra(stack_a);
	}
}

void	push_back_5(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*under;

	if (get_stack_size(*stack_b) == 2)
	{
		if ((*stack_b)->value < (*stack_b)->next->value)
			sb(stack_b);
	}
	while (is_stack_empty(*stack_b) == 0)
	{
		under = find_under(stack_a, *stack_b);
		if (get_index_a(stack_a, under) == 1)
		{
			while (under->back != NULL)
				ra(stack_a);
		}
		else
		{
			while (under->back != NULL)
				rra(stack_a);
		}
		pa(stack_a, stack_b);
	}
}

t_maillon	*find_under(t_maillon **stack_a, t_maillon *tmp)
{
	t_maillon	*i;
	t_maillon	*small;

	i = *stack_a;
	small = is_smallest(*stack_a);
	if (tmp->value < small->value)
		return (small);
	if (i->value != small->value && tmp->value < i->value)
	{
		while (i->value != small->value)
			i = i->next;
	}
	while (i && i->value < tmp->value)
	{
		i = i->next;
	}
	if (i == NULL)
		return (*stack_a);
	else
		return (i);
}

t_maillon	*is_smallest(t_maillon *stack_a)
{
	t_maillon	*tmp;
	t_maillon	*small;

	tmp = stack_a;
	small = stack_a->next;
	while (tmp)
	{
		if (tmp->value < small->value)
			small = tmp;
		tmp = tmp->next;
	}
	return (small);
}
