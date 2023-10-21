/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:49 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/27 22:39:18 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error(t_pile *stack)
{
	if (!stack)
		return ;
	ft_freestack(stack);
	write(2, "Error\n", 6);
	exit (1);
}

void	ft_freestack(t_pile *stack)
{
	t_node	*node;
	t_node	*tmp;

	node = stack->first;
	if (!stack)
		return ;
	while (node)
	{
		tmp = node;
		free(tmp);
		node = node->suivant;
	}
}

char	**ft_free(char **spliter, int i)
{
	while (i >= 0)
	{
		free(spliter[i]);
		i--;
	}
	free(spliter);
	spliter = NULL;
	return (spliter);
}

void	check_duplicates(t_pile *stack, int nb)
{
	t_node	*node;
	int		i;

	i = 0;
	node = stack->last;
	if (node == NULL)
		return ;
	while (node)
	{
		if (nb == node->valeur)
			error(stack);
		node = node->precedent;
	}
}
