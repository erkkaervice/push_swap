# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/20 15:44:12 by eala-lah          #+#    #+#              #
#    Updated: 2024/10/03 15:32:33 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

INCS        = -I ./inc/
LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR    = src/
SRCS        = $(addprefix $(SRC_DIR), $(SRC))
SRC         = \
    1-validation.c \
    2-stacking.c \
    3-indexing.c \
    4a-sorting.c \
    4b-tools.c \
    5-moving.c \
    main.c \
    push.c \
    reverse_rotate.c \
    rotate.c \
    swap.c

BONUS_SRC   = \
    checker_bonus.c \
    1-validation.c \
    2-stacking.c \
    3-indexing.c \
    4a-sorting.c \
    4b-tools.c \
    5-moving.c \
    push.c \
    swap.c \
    rotate.c \
    reverse_rotate.c

OBJ_DIR    = obj/
OBJS        = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_DIR), $(BONUS_SRC:.c=.o))

CC      = gcc
CFLAGS  = -Wall -Wextra -Werror

all: $(OBJ_DIR) $(LIBFT) $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(LIBFT):
	make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC"

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -L $(LIBFT_DIR) -lft

bonus: $(OBJ_DIR) $(BONUS_NAME)

clean:
	rm -rf $(OBJ_DIR)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)
	rm -f $(BONUS_NAME)

re: fclean all

.PHONY: all clean fclean re bonus
