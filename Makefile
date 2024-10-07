# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 15:36:34 by eala-lah          #+#    #+#              #
#    Updated: 2024/10/07 11:45:04 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        = push_swap
BONUS_NAME  = checker

INCS        = -I ./libft/inc/ -I ./inc/
LIBFT_DIR   = libft/
LIBFT       = $(LIBFT_DIR)/libft.a

SRC_DIR     = src/
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

OBJ_DIR     = obj/
OBJS        = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
BONUS_OBJS  = $(addprefix $(OBJ_DIR), $(BONUS_SRC:.c=.o))

CC          = gcc
CFLAGS      = -Wall -Wextra -Werror -fPIC
GIT_FLAGS   = git clone --depth 1

all: $(LIBFT) $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	@echo "Created object directory."

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		$(GIT_FLAGS) https://github.com/erkkaervice/libft.git $(LIBFT_DIR) || exit 1; \
	fi
	@make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC -I ./inc/" 2> /dev/stderr > /dev/null
	@echo "Libft library built."

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@
	@echo "Compiled $< into $@."

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft 2> /dev/stderr > /dev/null
	@echo "Executable $(NAME) created."

bonus: $(OBJ_DIR) $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -L $(LIBFT_DIR) -lft 2> /dev/stderr > /dev/null
	@echo "Executable $(BONUS_NAME) created."

clean:
	@rm -rf $(OBJ_DIR) 2> /dev/stderr > /dev/null
	@make -C $(LIBFT_DIR) clean 2> /dev/stderr > /dev/null
	@echo "Cleaned up $(OBJ_DIR) and library."

fclean: clean
	@rm -f $(LIBFT) $(NAME) $(BONUS_NAME) 2> /dev/stderr > /dev/null
	@rm -rf $(LIBFT_DIR) 2> /dev/stderr > /dev/null
	@echo "Fully cleaned up all generated files."

re: fclean all

.PHONY: all clean fclean re bonus
