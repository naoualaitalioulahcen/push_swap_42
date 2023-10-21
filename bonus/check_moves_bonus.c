/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 04:11:54 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/24 23:06:40 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushbonus.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	swap_all(t_pile *stack_a, t_pile *stack_b)
{
	swap(stack_a, 0);
	swap(stack_b, 0);
}

void	free_stacks(t_pile *stack_a, t_pile *stack_b)
{
	ft_freestack(stack_a);
	ft_freestack(stack_b);
	write(2, "Error\n", 6);
	exit (-1);
}

void	check_moves(t_pile *stack_a, t_pile	*stack_b, char *ligne)
{
	if (ft_strcmp(ligne, "pb\n"))
		push(stack_a, stack_b, 0);
	else if (ft_strcmp(ligne, "pa\n"))
		push(stack_b, stack_a, 0);
	else if (ft_strcmp(ligne, "sa\n"))
		swap(stack_a, 0);
	else if (ft_strcmp(ligne, "sb\n"))
		swap(stack_b, 0);
	else if (ft_strcmp(ligne, "ss\n"))
		swap_all(stack_b, stack_a);
	else if (ft_strcmp(ligne, "ra\n"))
		rotate(stack_a, 1, 0);
	else if (ft_strcmp(ligne, "rb\n"))
		rotate(stack_b, 1, 0);
	else if (ft_strcmp(ligne, "rr\n"))
		rotate_all(stack_b, stack_a, 1, 0);
	else if (ft_strcmp(ligne, "rra\n"))
		rotate(stack_a, 2, 0);
	else if (ft_strcmp(ligne, "rrb\n"))
		rotate(stack_b, 2, 0);
	else if (ft_strcmp(ligne, "rrr\n"))
		rotate_all(stack_b, stack_a, 2, 0);
	else
		free_stacks(stack_a, stack_b);
}
