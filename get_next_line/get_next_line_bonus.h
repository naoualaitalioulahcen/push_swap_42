/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:38:33 by nait-ali          #+#    #+#             */
/*   Updated: 2023/01/20 23:56:34 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

# include<fcntl.h>
# include<stdio.h>
# include<stdlib.h>
# include<unistd.h>
# include<unistd.h>

char	*get_next_line(int fd);
int		ft_strlen(char *str);
int		ft_contains(char *str, int n);
char	*ft_strdup(char *str);
char	*ft_read(int fd, char *tmp);
char	*reste(char *tmp);
char	*myline(char *tmp);
char	*ft_strjoin(char *str1, char *str2);

#endif
