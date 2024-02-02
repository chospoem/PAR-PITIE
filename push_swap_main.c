/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_main.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 22:53:24 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/31 15:57:54 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int ac, char **av)
{
	t_maillon	*stack_a;
	t_maillon	*stack_b;

	check_args_before(ac, av);
	stack_a = ini_stack_a(ac, av);
	stack_b = ft_lstnewm(NULL);
	if (fill_stack_a(ac, av, stack_a) == 1
		|| check_args_after(stack_a, stack_b) == 1)
		error_free(stack_a, stack_b);
	if (get_stack_size(stack_a) < 4)
		less_than_4(&stack_a);
	else if (get_stack_size(stack_a) < 6)
		less_than_6(&stack_a, &stack_b);
	else
		algo(&stack_a, &stack_b);
	no_error_free(stack_a, stack_b);
	return (0);
}
