# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rjeor-mo <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/10/23 17:23:16 by rjeor-mo          #+#    #+#              #
#    Updated: 2019/10/24 18:03:40 by rjeor-mo         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=ft_ls

VPATH=./

CC=gcc

LIBFT= -L libft/ -lftprintf

IDIR=./libft

INCLUDES= -I$(IDIR)

HEADERS= ft_ls.h

SRC= main.c ft_ls.c ft_lstrev.c ft_lstsort.c free_delete.c create_list.c print_ls.c

#CFLAGS= -Wall -Wextra -Werror $(INCLUDES) -O2 -march=native
CFLAGS= -Wall -Wextra $(INCLUDES)

RM= rm -f

all: $(NAME)

OBJ=$(SRC:.c=.o)

$(NAME): $(OBJ) $(HEADERS)
	make -C libft
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJ) $(LIBFT)
	@echo "Ft_ls ready."

%.o: %.c $(HEADERS)
	@$(CC) -c $< -o $@ $(CFLAGS)

clean:
	$(RM) $(OBJ)
	make -C libft clean

fclean: clean
	$(RM) $(NAME)
	make -C libft fclean

re: fclean all
