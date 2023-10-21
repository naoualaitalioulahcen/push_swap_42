/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushbonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 03:48:20 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/27 23:08:30 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHBONUS_H
# define PUSHBONUS_H

# include "../get_next_line/get_next_line.h"
# include "../src/push_swap.h"

void	check_moves(t_pile *stack_a, t_pile *stack_b, char *ligne);
int		ft_strcmp(char *s1, char *s2);
void	swap_all(t_pile *stack_a, t_pile *stack_b);
void	free_stacks(t_pile *stack_a, t_pile *stack_b);
#endif
