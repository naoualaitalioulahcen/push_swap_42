/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:59 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/28 00:25:35 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(char av[], t_pile *stack)
{
	char	**tableau;
	int		i;
	int		nb;

	tableau = ft_split(av, ' ');
	if (!(*tableau))
		error(stack);
	i = 0;
	while (tableau[i])
	{
		if (is_nbr(tableau[i]))
		{
			nb = ft_atoi(tableau[i]);
			check_duplicates(stack, nb);
			push_buttom(stack, lst_new(nb));
		}
		else
			error(stack);
		i++;
	}
	ft_free(tableau, i);
}

int	is_nbr(char *s)
{
	int	i;

	i = 0;
	if (s[i] == '+' || s[i] == '-')
		i++;
	if (!s[i])
		return (0);
	while (s[i])
	{
		if (!(s[i] >= '0' && s[i] <= '9'))
			return (0);
		i++;
	}
	return (1);
}

void	parsing(char **av, t_pile *stack)
{
	int		i;

	i = 1;
	while (av[i])
	{
		check_input(av[i], stack);
		i++;
	}
}
