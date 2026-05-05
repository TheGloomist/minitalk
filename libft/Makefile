# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: izaitcev <izaitcev@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2022/04/30 14:54:38 by izaitcev      #+#    #+#                  #
#    Updated: 2026/05/05 18:55:59 by iazaitce      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME 		= libft.a
CC 			= cc 
CFLAGS 		= -Wall -Wextra -Werror -g # -fsanitize=address

HEADERS	= -I ./include
SRC 	= $(shell find ./src -iname "*.c")
OBJS = $(SRC:%.c=%.o)

all: $(NAME)

%.o: %.c 
	@$(CC) $(CFLAGS) -c -o $@ $< $(HEADERS)

$(NAME): $(OBJS)
	@ar rc $(NAME) $(OBJS)
	
clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all bonus clean fclean re isprintf