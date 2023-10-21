/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:45 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/28 00:32:05 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_pile *stack, int type_rotate, char type)
{
	t_node	*node;

	if (stack->taille < 2)
		return ;
	if (type_rotate == 1)
	{
		node = pop_top(stack);
		push_buttom(stack, node);
		if (type == 'a')
			write(1, "ra\n", 3);
		else if (type == 'b')
			write(1, "rb\n", 3);
	}
	else if (type_rotate == 2)
	{
		node = pop_bottum(stack);
		push_top(stack, node);
		if (type == 'a')
			write(1, "rra\n", 4);
		else if (type == 'b')
			write(1, "rrb\n", 4);
	}
}

void	push(t_pile *s1, t_pile *s2, char type)
{
	t_node	*node;

	if (!s1->taille)
		return ;
	node = pop_top(s1);
	push_top(s2, node);
	if (type == 'a')
		write(1, "pa\n", 3);
	else if (type == 'b')
		write(1, "pb\n", 3);
}

void	swap(t_pile *stack, char type)
{
	t_node	*last;
	int		tmp;

	if (stack->taille <= 1)
		return ;
	last = stack->last;
	tmp = last->valeur;
	last->valeur = last->precedent->valeur;
	last->precedent->valeur = tmp;
	tmp = last->indice;
	last->indice = last->precedent->indice;
	last->precedent->indice = tmp;
	if (type == 'a')
		write(1, "sa\n", 3);
	else if (type == 'b')
		write(1, "sb\n", 3);
}
