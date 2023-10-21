/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 03:50:53 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/27 23:58:21 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushbonus.h"

int	is_sorted(t_pile stack)
{
	int		i;
	t_node	*node;

	node = stack.first;
	i = stack.taille;
	while (node)
	{
		if (node->indice != i)
			return (0);
		i--;
		node = node->suivant;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_pile	stack_a;
	t_pile	stack_b;
	char	*ligne;

	if (ac < 2)
		exit (0);
	stack_a.taille = 0;
	parsing(av, &stack_a);
	index_stack(&stack_a);
	ligne = get_next_line(0);
	while (ligne)
	{
		check_moves(&stack_a, &stack_b, ligne);
		free(ligne);
		ligne = get_next_line(0);
	}
	free(ligne);
	if (is_sorted(stack_a) && !stack_b.taille)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	ft_freestack(&stack_a);
	ft_freestack(&stack_b);
	return (0);
}
