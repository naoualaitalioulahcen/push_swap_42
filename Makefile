# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nait-ali <nait-ali@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/06/27 22:20:57 by nait-ali          #+#    #+#              #
#    Updated: 2023/06/27 22:45:39 by nait-ali         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = cc 

CFLAGS = -Wall -Wextra -Werror

FILES =  src/les_outiles.c  src/main.c src/parsing.c  src/update_stack.c src/parsing_utils_1.c src/parsing_utils_2.c \
src/index_stack.c src/sort.c src/operations.c src/best_moves.c src/positions.c src/rotate.c src/ft_split.c  \
src/best_moves_utils.c

FILES_BONUS = bonus/main_bonus.c bonus/check_moves_bonus.c \
get_next_line/get_next_line_utils.c get_next_line/get_next_line.c src/les_outiles.c  \
src/parsing.c  src/update_stack.c src/parsing_utils_1.c src/parsing_utils_2.c \
src/index_stack.c src/sort.c src/operations.c  src/positions.c src/rotate.c src/ft_split.c  \

OBJS = $(FILES:.c=.o)

OBJS_BONUS = $(FILES_BONUS:.c=.o)

all:$(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS)  -o $(NAME) 

bonus: $(OBJS_BONUS)
		$(CC)  $(CFLAGS) $(OBJS_BONUS)  -o $(BONUS) 

clean:
	rm -f $(OBJS)
	rm -f $(OBJS_BONUS)

bonus/%.o : bonus/%.c bonus/pushbonus.h
	$(CC) $(CFLAGS) -c  $< -o $@ 

src/%.o : src/%.c src/push_swap.h
	$(CC) $(CFLAGS) -c  $< -o $@ 

fclean: clean
	rm -f $(NAME)
	rm -f $(BONUS)


re : fclean all

.PHONY: all clean fclean re