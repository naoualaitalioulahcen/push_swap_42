/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:59:13 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/23 19:35:39 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_alls(t_pile *s_a, t_pile *s_b, int *m_a, int *m_b)
{
	while ((*m_a) * (*m_b) > 0)
	{
		if ((*m_a) > 0)
		{
			rotate_all(s_a, s_b, 1, 2);
			(*m_a)--;
			(*m_b)--;
		}
		else
		{
			rotate_all(s_a, s_b, 2, 2);
			(*m_a)++;
			(*m_b)++;
		}
	}
}

void	rotate_all(t_pile *s_a, t_pile *s_b, int type_rotation, char type)
{
	rotate(s_a, type_rotation, type);
	rotate(s_b, type_rotation, type);
	if (type == 2)
	{
		if (type_rotation == 1)
			write(1, "rr\n", 3);
		else if (type_rotation == 2)
			write(1, "rrr\n", 4);
	}
}

void	rotate_stack(t_pile *stack, int *m, char type)
{
	while (*m)
	{
		if (*m > 0)
		{
			rotate(stack, 1, type);
			(*m)--;
		}
		else
		{
			rotate(stack, 2, type);
			(*m)++;
		}
	}
}
