/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:49:59 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/18 16:32:35 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	algo(t_maillon **stack_a, t_maillon **stack_b)
{
	t_maillon	*cheapest;

	first_in_b(stack_a, stack_b);
	while (is_it_empty(*stack_a) == 0)
	{
		cheapest = find_cheapest(stack_a, stack_b);
		on_top_a(stack_a, cheapest);
		if (is_it_empty((*stack_b)) == 0)
			on_top_b(stack_b, cheapest);
		pb(stack_a, stack_b);
	}
	if (is_b_sorted((*stack_b)) == 1)
		end_sort(stack_b);
	if (is_b_sorted((*stack_b)) == 0)
	{
		while (is_it_empty((*stack_b)) == 0)
			pa(stack_a, stack_b);
	}
}

void	end_sort(t_maillon **stack_b)
{
	long int	index;
	t_maillon	*tmp;
	t_maillon	*biggest;
	long int	i;

	index = (get_stack_size((*stack_b)) / 2);
	tmp = (*stack_b);
	biggest = find_biggest((*stack_b));
	i = 0;
	while (tmp)
	{
		if (tmp->value == biggest->value)
		{
			if (i > index)
				end_sort2(stack_b, 0);
			else
				end_sort2(stack_b, 1);
		}
		i++;
		tmp = tmp->next;
	}
}

void	end_sort2(t_maillon **stack_b, int sens)
{
	if (sens == 0)
	{
		while (is_b_sorted((*stack_b)) == 1)
			rrb(stack_b);
	}
	else
	{
		while (is_b_sorted((*stack_b)) == 1)
			rb(stack_b);
	}
}

void	on_top_a(t_maillon **stack_a, t_maillon *tmp)
{
	long int	cost;

	cost = get_cost_a(*stack_a, tmp);
	while (cost > 0)
	{
		ra(stack_a);
		cost--;
	}
	while (cost < 0)
	{
		rra(stack_a);
		cost++;
	}
}

void	on_top_b(t_maillon **stack_b, t_maillon *tmp)
{
	long int	cost;

	cost = get_cost_b((*stack_b), tmp);
	while (cost > 0)
	{
		rb(stack_b);
		cost--;
	}
	while (cost < 0)
	{
		rrb(stack_b);
		cost++;
	}
}
