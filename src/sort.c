/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:55:11 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/27 23:03:10 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_3(t_pile *stack)
{
	t_node	*first;
	t_node	*last;
	t_node	*mil;

	first = stack->first;
	mil = first->suivant;
	last = stack->last;
	if (mil->valeur > first->valeur && mil->valeur > last->valeur)
		rotate(stack, 2, 'a');
	if (last->valeur > mil->valeur && last->valeur > first->valeur)
		rotate(stack, 1, 'a');
	first = stack->first;
	mil = first->suivant;
	last = stack->last;
	if (last->valeur > mil->valeur)
		swap(stack, 'a');
}

void	first_sort(t_pile *stack_a, t_pile *stack_b)
{
	int		size;
	int		i;
	int		nbr_push;
	int		mil;

	i = 0;
	size = stack_a->taille;
	mil = size / 2;
	nbr_push = 0;
	while (i < size && size > 6 && nbr_push < mil)
	{
		if (stack_a->last->indice > mil)
			rotate(stack_a, 1, 'a');
		else
		{
			push(stack_a, stack_b, 'b');
			nbr_push++;
		}
		i++;
	}
	while (size - nbr_push++ > 3)
		push(stack_a, stack_b, 'b');
	sort_3(stack_a);
}

void	last_sort(t_pile *stack)
{
	int		size;
	t_node	*node;

	node = stack->last;
	size = stack->taille;
	while (is_sorted((*stack)))
	{
		node = stack->last;
		set_position(stack);
		if (node->indice - node->position != 1)
			rotate(stack, 1, 'a');
	}
}
