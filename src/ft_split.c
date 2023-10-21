/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/22 05:36:41 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/23 19:36:52 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ft_strlen(const	char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*t;

	if (!s)
		return (0);
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	t = calloc(len + 1, sizeof(char));
	if (!t)
		return (0);
	if (start < ft_strlen(s) && len > 0)
		ft_memcpy(t, s + start, len);
	return (t);
}

char	**ft_split(char const *s, char c)
{
	char	**str;
	int		i;

	i = 0;
	if (!s)
		return (0);
	str = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!str)
		return (0);
	while (*s)
	{
		while (*s && *s == c)
			s++;
		if (*s)
		{
			str[i] = ft_substr(s, 0, ft_wordlen(s, c));
			if (!str[i])
				return (ft_freestr(str));
			i++;
		}
		while (*s && *s != c)
			s++;
	}
	str[i] = NULL;
	return (str);
}
