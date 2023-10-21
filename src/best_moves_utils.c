/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_moves_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 17:35:32 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/23 19:37:07 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	val_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

int	number_moves(int a, int b)
{
	if (a * b > 0)
	{
		a = val_abs(a);
		b = val_abs(b);
		if (a >= b)
			return (a);
		else if (a < b)
			return (b);
	}
	return (val_abs(a) + val_abs(b));
}
