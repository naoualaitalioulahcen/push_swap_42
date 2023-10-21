/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 21:54:35 by nait-ali          #+#    #+#             */
/*   Updated: 2023/06/27 23:10:00 by nait-ali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_node
{
	int				valeur;
	int				indice;
	int				position;
	int				tposition;
	int				ma;
	int				mb;
	struct s_node	*suivant;
	struct s_node	*precedent;
}	t_node;

typedef struct s_pile
{
	int		taille;
	t_node	*first;
	t_node	*last;
}	t_pile;

void	parsing(char **av, t_pile *stack);
void	init_pile(t_pile *stack);
char	**ft_split(char const *s, char c);
int		is_number(char *str);
int		ft_atoi(const char *str);
void	check_duplicates(t_pile *stack, int nb);
char	**ft_free(char **spliter, int i);
void	check_input(char av[], t_pile *stack);
void	ft_freestack(t_pile *stack);
void	error(t_pile *stack);
t_node	*pop_bottum(t_pile *stack);
void	push_buttom(t_pile *stack, t_node *node);
void	push_top(t_pile *stack, t_node *node);
t_node	*lst_new(int data);
void	set_index(t_pile *stack, int max, int index);
void	index_stack(t_pile *stack);
void	rotate(t_pile *stack, int type_rotate, char type);
t_node	*pop_top(t_pile *stack);
void	first_sort(t_pile *stack_a, t_pile *stack_b);
void	push(t_pile *from, t_pile *to, char type);
void	sort_3(t_pile *stack);
void	swap(t_pile *stack, char type);
int		ft_wordlen(char const *str, char c);
void	*ft_memcpy(void *dst, const void *src, size_t n);
char	**ft_freestr(char	**str);
int		count_words(char const *s, char c);
int		is_nbr(char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
void	set_position(t_pile *stack);
void	set_targetposition(t_pile *stack_a, t_pile *stack_b);
void	find_targetposition(t_node *node_a, t_node *node_b, int idx);
void	best_moves(t_pile *stack_a, t_pile *stack_b);
void	rotate_all(t_pile *s_a, t_pile *s_b, int type_rotation, char type);
void	rotate_alls(t_pile *s_a, t_pile *s_b, int *m_a, int *m_b);
void	moves_stack(t_pile *stack_a, t_pile *stack_b, t_node *node);
int		number_moves(int a, int b);
void	minimum_moves(t_pile *stack_a, t_pile *stack_b);
void	rotate_stack(t_pile *stack, int *m, char type);
void	count_moves(t_pile *stack_b, t_pile *stack_a);
void	last_sort(t_pile *stack);
int		is_sorted(t_pile stack);
#endif
