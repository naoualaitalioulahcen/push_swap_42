/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:37:46 by nait-ali          #+#    #+#             */
/*   Updated: 2023/01/21 00:34:33 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read_fd(int fd, char *tmp)
{
	int		i;
	char	*buff;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (free(tmp), NULL);
	i = 1;
	while (i && !ft_contains(tmp, '\n'))
	{
		i = read(fd, buff, BUFFER_SIZE);
		if (i < 0)
			return (free(buff), free(tmp), NULL);
		buff[i] = '\0';
		tmp = ft_strjoin(tmp, buff);
		if (!tmp)
			return (free(buff), NULL);
	}
	return (free(buff), tmp);
}

char	*reste(char *tmp)
{
	char	*rst;
	int		i;
	int		l;

	if (!tmp)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (!tmp[i])
		return (free(tmp), NULL);
	i++;
	l = ft_strlen(&tmp[i]);
	rst = (char *)malloc(l + 1);
	if (!rst)
		return (free(tmp), NULL);
	l = 0;
	while (tmp[i])
		rst[l++] = tmp[i++];
	rst[l] = '\0';
	return (free(tmp), rst);
}

char	*myline(char *tmp)
{
	int		i;
	char	*ligne;

	i = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i] && tmp[i] != '\n')
		i++;
	if (tmp[i] == '\0')
		ligne = (char *)malloc(i + 1);
	else
		ligne = (char *)malloc(i + 2);
	if (!ligne)
		return (NULL);
	i = 0;
	while (tmp[i] && tmp[i] != '\n')
	{
		ligne[i] = tmp[i];
		i++;
	}
	if (tmp[i] == '\n')
		ligne[i++] = '\n';
	ligne[i] = '\0';
	return (ligne);
}

char	*get_next_line(int fd)
{
	char		*nl;
	static char	*tmp[10240];

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	tmp[fd] = ft_read_fd(fd, tmp[fd]);
	if (!tmp[fd])
		return (NULL);
	if (!tmp[fd][0])
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	nl = myline(tmp[fd]);
	if (!nl)
	{
		free(tmp[fd]);
		tmp[fd] = NULL;
		return (NULL);
	}
	tmp[fd] = reste(tmp[fd]);
	return (nl);
}
