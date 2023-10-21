/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   positions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:55:06 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/24 23:03:02 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_pile *stack)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->last;
	while (node)
	{
		node->position = i;
		i++;
		node = node->precedent;
	}
}

void	set_targetposition(t_pile *stack_a, t_pile *stack_b)
{
	t_node	*node_a;
	t_node	*node_b;

	node_b = stack_b->last;
	while (node_b)
	{
		node_a = stack_a->last;
		find_targetposition(node_a, node_b, INT_MAX);
		node_b = node_b->precedent;
	}
}

void	find_targetposition(t_node *node_a, t_node *node_b, int n)
{
	t_node	*tmp;

	tmp = node_a;
	while (tmp)
	{
		if (tmp->indice > node_b->indice && tmp->indice < n)
		{
			n = tmp->indice;
			node_b->tposition = tmp->position;
		}
		tmp = tmp->precedent;
	}
	if (n == INT_MAX)
	{
		tmp = node_a;
		while (tmp)
		{
			if (tmp->indice < n)
			{
				n = tmp->indice;
				node_b->tposition = tmp->position;
			}
			tmp = tmp->precedent;
		}
	}
}
