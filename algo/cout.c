/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cout.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 17:48:07 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/18 15:53:04 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

/*
1. trouver l'index
2. calculer cb de mouvements pr amener en haut de A
3. calculer cb de mouvements pr arriver en haut de B.
4. +1 pr le push
*/

t_maillon	*find_cheapest(t_maillon **stack_a, t_maillon **stack_b)
{
	long int	cheapest;
	long int	res;
	t_maillon	*tmp;
	t_maillon	*cheap;

	tmp = (*stack_a);
	cheapest = get_cost((*stack_a), (*stack_b), tmp);
	cheap = tmp;
	while (tmp->next != NULL)
	{
		res = get_cost((*stack_a), (*stack_b), tmp);
		if (res < cheapest)
		{
			cheapest = res;
			cheap = tmp;
		}
		tmp = tmp->next;
	}
	return (cheap);
}

long int	get_cost(t_maillon *stack_a, t_maillon *stack_b, t_maillon *tmp)
{
	long int	res_a;
	long int	res_b;
	long int	final_cost;

	res_a = get_cost_a(stack_a, tmp);
	res_b = get_cost_b(stack_b, tmp);
	if (res_a < 0)
		res_a = res_a * -1;
	if (res_b < 0)
		res_b = res_b * -1;
	final_cost = res_a + res_b;
	return (final_cost);
}

long int	get_cost_a(t_maillon *stack_a, t_maillon *tmp)
{
	long int	cost;

	cost = find_index(stack_a, tmp);
	if (cost > get_stack_size(stack_a) / 2)
		cost = (get_stack_size(stack_a) - cost) * -1;
	return (cost);
}

long int	find_index(t_maillon *stack_b, t_maillon *value)
{
	t_maillon	*tmp;
	long int	i;

	tmp = stack_b;
	i = 0;
	while (tmp->next)
	{
		if (tmp->value == value->value)
			return (i);
		i++;
		tmp = tmp->next;
	}
	if (tmp->value == value->value)
		return (i);
	return (-1);
}

long int	get_cost_b(t_maillon *stack_b, t_maillon *tmp)
{
	t_maillon	*before;
	t_maillon	*after;
	t_maillon	*i;

	i = stack_b;
	while (i)
	{
		if (i->back != NULL)
			before = i->back;
		else
			before = get_last(stack_b);
		after = i;
		if ((before->value > tmp->value && after->value < tmp->value))
		{
			if (find_index(stack_b, i) <= (get_stack_size(stack_b) / 2))
				return (find_index(stack_b, i));
			else
				return ((get_stack_size(stack_b)
						- find_index(stack_b, i)) * -1);
		}
		i = i->next;
	}
	return (find_index(stack_b, find_max(stack_b)));
}
