/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: csaunier <csaunier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 03:02:49 by csaunier          #+#    #+#             */
/*   Updated: 2024/01/31 15:17:44 by csaunier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct s_maillon
{
	long int			value;
	struct s_maillon	*back;
	struct s_maillon	*next;
}	t_maillon;

int			main(int ac, char **av);
int			check_args_before(int ac, char **av);
int			check_args_before2(int ac, char **av);
int			check_quotes(char **av);
int			check_char(char *av);
int			ft_is_an_int(char *av);
int			check_args_after(t_maillon *stack_a, t_maillon *stack_b);
int			is_a_sorted(t_maillon *stack_a);
int			is_there_dupl(t_maillon *stack_a);
t_maillon	*ini_stack_a(int ac, char **av);
int			fill_quotes(char **av, t_maillon *stack_a);
t_maillon	*ft_lstnewm(void *content);
int			fill_stack_a(int ac, char **av, t_maillon *stack_a);
int			push_back_new(t_maillon *stack_a, long int x);
void		error_no_free(void);
void		error_free(t_maillon *stack_a, t_maillon *stack_b);
void		no_error_free(t_maillon *stack_a, t_maillon *stack_b);
void		free_stack(t_maillon *stack);
void		free_str(char **str);
int			is_stack_empty(t_maillon *stack);
void		pa(t_maillon **stack_a, t_maillon **stack_b);
void		first_in_a(t_maillon **stack_a, t_maillon **stack_b);
void		last_in_b(t_maillon **stack_a, t_maillon **stack_b);
void		pb(t_maillon **stack_a, t_maillon **stack_b);
void		first_in_b(t_maillon **stack_a, t_maillon **stack_b);
void		last_in_a(t_maillon **stack_a, t_maillon **stack_b);
void		sa(t_maillon **stack_a);
void		sb(t_maillon **stack_b);
void		ss(t_maillon **stack_a, t_maillon **stack_b);
void		ra(t_maillon **stack_a);
void		rb(t_maillon **stack_b);
void		rr(t_maillon **stack_a, t_maillon **stack_b);
void		rra(t_maillon **stack_a);
void		rrb(t_maillon **stack_b);
void		rrr(t_maillon **stack_a, t_maillon **stack_b);
void		less_than_4(t_maillon **stack_a);
int			is_biggest_end(t_maillon **stack_a);
t_maillon	*find_last(t_maillon *stack_a);
t_maillon	*find_biggest(t_maillon *stack_a);
void		algo(t_maillon **stack_a, t_maillon **stack_b);
void		end_sort(t_maillon **stack_b);
void		end_sort2(t_maillon **stack_b, int sens);
void		on_top_a(t_maillon **stack_a, t_maillon *tmp);
void		on_top_b(t_maillon **stack_b, t_maillon *tmp);
int			is_it_empty(t_maillon *stack);
int			is_b_sorted(t_maillon *stack_b);
t_maillon	*find_cheapest(t_maillon **stack_a, t_maillon **stack_b);
long int	get_cost(t_maillon *stack_a, t_maillon *stack_b, t_maillon *tmp);
long int	get_cost_a(t_maillon *stack_a, t_maillon *tmp);
long int	get_cost_b(t_maillon *stack_b, t_maillon *tmp);
t_maillon	*get_last(t_maillon *stack_b);
long int	get_stack_size(t_maillon *stack);
int			get_index_a(t_maillon **stack_a, t_maillon *tmp);
int			get_index_b(t_maillon **stack_b, t_maillon *tmp);
long int	find_index(t_maillon *stack_b, t_maillon *value);
void		less_than_6(t_maillon **stack_a, t_maillon **stack_b);
t_maillon	*find_max(t_maillon *stack_b);
void		push_back_5(t_maillon **stack_a, t_maillon **stack_b);
t_maillon	*find_under(t_maillon **stack_a, t_maillon *tmp);
t_maillon	*is_smallest(t_maillon *stack_a);

#endif