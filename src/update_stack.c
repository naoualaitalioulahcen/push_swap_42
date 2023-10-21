/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   update_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:55:17 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/24 00:06:09 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*lst_new(int data)
{
	t_node	*new;

	new = (t_node *)malloc(sizeof(t_node));
	if (!new)
		exit(1);
	new->valeur = data;
	new->indice = 0;
	new->suivant = NULL;
	new->precedent = NULL;
	return (new);
}

void	push_top(t_pile *stack, t_node *node)
{
	t_node	*last;

	if (!stack->taille)
		stack->first = node;
	else
	{
		last = stack->last;
		node->precedent = last;
		last->suivant = node;
	}
	stack->last = node;
	stack->taille++;
}

t_node	*pop_top(t_pile *stack)
{
	t_node	*p;

	if (!stack->taille)
		return (NULL);
	p = stack->last;
	if (stack->taille == 1)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->last = p->precedent;
		stack->last->suivant = NULL;
		p->precedent = NULL;
	}
	stack->taille--;
	return (p);
}

void	push_buttom(t_pile *stack, t_node *node)
{
	t_node	*first;

	first = stack->first;
	if (!stack->taille)
		stack->last = node;
	else
	{
		first->precedent = node;
		node->suivant = first;
	}
	stack->first = node;
	stack->taille ++;
}

t_node	*pop_bottum(t_pile *stack)
{
	t_node	*pop;

	if (!stack->taille)
		return (NULL);
	pop = stack->first;
	if (stack->taille == 1)
	{
		stack->first = NULL;
		stack->last = NULL;
	}
	else
	{
		stack->first = pop->suivant;
		stack->first->precedent = NULL;
		pop->precedent = NULL;
		pop->suivant = NULL;
	}
	stack->taille --;
	return (pop);
}
