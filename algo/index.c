/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaapatou <aaapatou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/03 11:25:35 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/06 15:49:07 by aaapatou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*2. trouver si le maillon est au dessus ou en dessous de la moitié de la stack.
-> pr A trouver si tmp est au dessus ou en dessous de la moitié de la stack
pr savoir si ra ou rra
-> pr B savoir si la valeur du milieu est plus ou moins grande que tmp*/

#include "../includes/push_swap.h"

long int	get_stack_size(t_maillon *stack)
{
	long int	size;
	t_maillon	*tmp;

	size = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

/* return 1 si il dépasse l'"index donc rra"*/
int	get_index_a(t_maillon **stack_a, t_maillon *tmp)
{
	long int	index;
	long int	count;
	t_maillon	*i;

	index = ((get_stack_size((*stack_a))) / 2);
	i = (*stack_a);
	count = 0;
	while (i->next != NULL)
	{
		if (i->value == tmp->value)
		{
			if (count > index)
				return (1);
			else
				return (0);
		}
		i = i->next;
		count++;
	}
	return (0);
}

/* si la valeur est plus peite que l"indezx je renvoie 1 donc rra*/

int	get_index_b(t_maillon **stack_b, t_maillon *tmp)
{
	long int	i;
	t_maillon	*j;

	i = ((get_stack_size((*stack_b))) / 2);
	j = (*stack_b);
	while (j->next != NULL && i > 0)
	{
		j = j->next;
		i--;
	}
	if (tmp->value < j->value)
		return (1);
	else
		return (0);
}
