/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:31 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/28 00:03:57 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_pile stack)
{
	int		i;
	t_node	*node;

	node = stack.first;
	i = stack.taille;
	while (node)
	{
		if (node->indice != i)
			return (1);
		i--;
		node = node->suivant;
	}
	return (0);
}

int	main(int ac, char **av)
{
	t_pile	stack_a;
	t_pile	stack_b;

	if (ac < 2)
		exit(0);
	stack_a.taille = 0;
	parsing(av, &stack_a);
	index_stack(&stack_a);
	if (!is_sorted(stack_a))
	{
		ft_freestack(&stack_a);
		exit (0);
	}
	first_sort(&stack_a, &stack_b);
	while (stack_b.last)
	{
		set_position(&stack_a);
		set_position(&stack_b);
		set_targetposition(&stack_a, &stack_b);
		best_moves(&stack_a, &stack_b);
	}
	set_position(&stack_a);
	last_sort(&stack_a);
	ft_freestack(&stack_a);
	return (0);
}
