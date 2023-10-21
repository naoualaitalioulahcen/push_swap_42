/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:33:27 by nait-ali          #+#    #+#             */
/*   Updated: 2023/01/20 22:07:05 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_contains(char *str, int n)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == (char)n)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strdup(char *str)
{
	char	*p;
	int		l;
	int		i;

	l = ft_strlen(str);
	i = 0;
	p = (char *)malloc(l + 1);
	if (!p)
		return (0);
	while (str[i])
	{
		p[i] = str[i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*p;
	int		i;
	int		j;

	if (!str1)
		str1 = ft_strdup("");
	if (!str1 || !str2)
		return (free(str1), NULL);
	p = (char *)malloc(ft_strlen(str1) + 1 + ft_strlen(str2));
	if (!p)
		return (free(str1), NULL);
	i = 0;
	while (str1[i])
	{
		p[i] = str1[i];
		i++;
	}
	j = 0;
	while (str2[j])
	{
		p[i + j] = str2[j];
		j++;
	}
	return (p[i + j] = '\0', free(str1), p);
}
