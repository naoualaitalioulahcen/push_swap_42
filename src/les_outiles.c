/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   les_outiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:27 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/23 19:36:39 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_words(char const *s, char c)
{
	int		i;
	int		var;
	int		j;
	char	*str;

	i = 0;
	var = 0;
	j = 0;
	str = (char *)s;
	while (str[j])
	{
		if (str[j] != c && var == 0)
		{
			var = 1;
			i++;
		}
		else if (str[j] == c)
			var = 0;
		j++;
	}
	return (i);
}

int	ft_wordlen(char const *str, char c)
{
	int		i;
	char	*s;

	i = 0;
	s = (char *)str;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_freestr(char	**str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
	return (NULL);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*temp1;
	unsigned char	*temp2;

	if (!dst && !src)
		return (0);
	temp1 = (unsigned char *)dst;
	temp2 = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		temp1[i] = temp2[i];
		i++;
	}
	return (dst);
}
