/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:22 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/23 19:36:47 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	index_stack(t_pile *stack)
{
	t_node	*node;
	int		index;
	int		max;

	index = stack->taille;
	while (index)
	{
		node = stack->last;
		max = INT_MIN;
		while (node)
		{
			if (node->valeur > max && node->indice == 0)
				max = node->valeur;
			node = node->precedent;
		}
		set_index(stack, max, index);
		index--;
	}
}

void	set_index(t_pile *stack, int max, int index)
{
	t_node	*node;

	node = stack->last;
	while (node)
	{
		if (node->valeur == max)
		{
			node->indice = index;
			return ;
		}
		node = node->precedent;
	}
}
