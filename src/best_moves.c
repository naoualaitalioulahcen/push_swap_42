/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:53:32 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/24 03:19:18 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	best_moves(t_pile *stack_a, t_pile *stack_b)
{
	count_moves(stack_b, stack_a);
	minimum_moves(stack_a, stack_b);
}

void	count_moves(t_pile *stack_b, t_pile *stack_a)
{
	t_node	*node;
	int		m_a;
	int		m_b;
	int		size_b;
	int		size_a;

	node = stack_b->last;
	size_b = stack_b->taille;
	size_a = stack_a->taille;
	while (node)
	{
		m_b = node->position;
		m_a = node->tposition;
		if (node->position > size_b / 2)
			m_b = (size_b - node->position) * -1;
		if (node->tposition > size_a / 2)
			m_a = (size_a - node->tposition) * -1;
		node->ma = m_a;
		node->mb = m_b;
		node = node->precedent;
	}
}

void	minimum_moves(t_pile *stack_a, t_pile *stack_b)
{
	t_node	*node;
	t_node	*n_node;
	int		min;
	int		nbr_mov;

	min = INT_MAX;
	node = stack_b->last;
	while (node)
	{
		nbr_mov = number_moves(node->ma, node->mb);
		if (nbr_mov < min)
		{
			min = nbr_mov;
			n_node = node;
		}
		node = node->precedent;
	}
	moves_stack(stack_a, stack_b, n_node);
}

void	moves_stack(t_pile *stack_a, t_pile *stack_b, t_node	*node)
{
	int	signe;

	signe = (node->ma) * (node->mb);
	if (signe > 0)
		rotate_alls(stack_a, stack_b, &node->ma, &node->mb);
	rotate_stack(stack_a, &(node->ma), 'a');
	rotate_stack(stack_b, &(node->mb), 'b');
	push(stack_b, stack_a, 'a');
}
