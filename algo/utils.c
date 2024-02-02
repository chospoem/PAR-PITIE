/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 15:50:38 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/21 15:02:33 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	is_it_empty(t_maillon *stack)
{
	long int	count;
	t_maillon	*tmp;

	count = 1;
	tmp = stack;
	while (tmp != NULL)
	{
		count++;
		tmp = tmp->next;
	}
	if (count > 1)
		return (0);
	else
		return (1);
}

int	is_b_sorted(t_maillon *stack_b)
{
	t_maillon	*tmp;

	tmp = stack_b;
	while (tmp->next != NULL)
	{
		if (tmp->value < tmp->next->value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

t_maillon	*get_last(t_maillon *stack_b)
{
	t_maillon	*tmp;

	tmp = stack_b;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

t_maillon	*find_max(t_maillon *stack_b)
{
	t_maillon	*tmp;
	t_maillon	*maxvalue;

	tmp = stack_b;
	maxvalue = tmp;
	while (tmp)
	{
		if (tmp->value > maxvalue->value)
			maxvalue = tmp;
		tmp = tmp->next;
	}
	return (maxvalue);
}
