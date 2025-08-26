# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/06 14:07:55 by tsodre-p          #+#    #+#              #
#    Updated: 2025/08/26 12:08:20 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = srcs/push_swap.c srcs/start_stacks.c srcs/swap_operations.c srcs/push_operations.c \
		srcs/rotate_operations.c srcs/rev_rotate_operations.c srcs/sort_operations.c srcs/sort_numbers_utils.c \
		srcs/sort_operations_utils.c srcs/sort_operations_utils_2.c srcs/indexing.c

OBJ = $(FILES:%.c=%.o)
FILES_O = srcs/push_swap.o srcs/start_stacks.o srcs/swap_operations.o srcs/push_operations.o \
			srcs/rotate_operations.o srcs/rev_rotate_operations.o srcs/sort_operations.o srcs/sort_numbers_utils.o \
			srcs/sort_operations_utils.o srcs/sort_operations_utils_2.o srcs/indexing.o
all: $(NAME)

$(LIBFT):
	@$(MAKE) -C ./libft

$(NAME): $(OBJ) $(LIBFT)
		@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o push_swap

clean:
		@$(MAKE) clean -C ./libft
		@$(RM) $(FILES_O)

fclean: clean
		@$(MAKE) fclean -C ./libft
		@$(RM) $(NAME)

re: fclean all
