# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ialvarez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/24 19:41:46 by ialvarez          #+#    #+#              #
#    Updated: 2022/03/08 21:09:42 by ialvarez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = server
NAMETWO = client

SRCS = server.c
SRCS2 = client.c

LIBFT_DIR = libft/
LIB_NAME = $(LIBFT_DIR)libft.a
INCLUDES = -I. -I$(LIBFT_DIR)
FSANITIZE = -g3 -fsanitize=address
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME) $(NAMETWO)

$(NAME): $(SRCS)
	@make -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(SRCS) -L ./libft/ -lft -o $(NAME)

$(NAMETWO): $(SRCS2)
	@$(CC) $(CFLAGS) $(SRCS2) -L ./libft/ -lft -o $(NAMETWO)

debug: $(SRCS) $(SRCS2)
	@make -s -C $(LIBFT_DIR)
	@$(CC) $(CFLAGS) $(FSANITIZE) $^ -L ./libft/ -l ft -o $(NAME)

clean:
	@make -C $(LIBFT_DIR) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIBFT_DIR) fclean
	@rm -f $(NAME)
	@rm -f $(NAMETWO)


re: fclean all

.PHONY:
			clean
			fclean
			all
			re
			bonus
