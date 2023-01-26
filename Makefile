# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tsodre-p <tsodre-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 14:26:29 by tsodre-p          #+#    #+#              #
#    Updated: 2023/01/26 13:02:00 by tsodre-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

LIBFT = libft/libft.a

CC = cc
RM = rm -f
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

FILES = srcs/start_stacks.c srcs/sa.c srcs/sb.c  srcs/ss.c srcs/pa.c srcs/pb.c

OBJ = $(FILES:%.c=%.o)
FILES_O = srcs/start_stacks.o srcs/sa.o srcs/sb.o srcs/ss.o srcs/pa.o srcs/pb.o

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
