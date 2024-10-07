# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 15:36:34 by eala-lah          #+#    #+#              #
#    Updated: 2024/10/07 12:29:08 by eala-lah         ###   ########.fr        #
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
	@mkdir -p $(OBJ_DIR) 2> /dev/null || { echo "Failed to create object directory." >&2; exit 1; }

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		$(GIT_FLAGS) https://github.com/erkkaervice/libft.git $(LIBFT_DIR) > /dev/null 2>&1 || { echo "Failed to clone libft repository." >&2; exit 1; }; \
	fi
	@make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC -I ./inc/" > /dev/null 2>&1 || { echo "Failed to build libft library." >&2; exit 1; }

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ > /dev/null 2>&1 || { echo "Compilation failed for $<." >&2; exit 1; }

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft || { echo "Linking failed for $(NAME)." >&2; exit 1; }

bonus: $(OBJ_DIR) $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	@$(CC) $(CFLAGS) $(BONUS_OBJS) -o $(BONUS_NAME) -L $(LIBFT_DIR) -lft || { echo "Linking failed for $(BONUS_NAME)." >&2; exit 1; }

clean:
	@rm -rf $(OBJ_DIR) 2> /dev/null || { echo "Failed to clean object files." >&2; }
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1 || { echo "Failed to clean libft." >&2; }

fclean: clean
	@rm -f $(LIBFT) $(NAME) $(BONUS_NAME) 2> /dev/null || { echo "Failed to fully clean up." >&2; }
	@rm -rf $(LIBFT_DIR) 2> /dev/null || { echo "Failed to remove libft directory." >&2; }

re: fclean all

.PHONY: all clean fclean re bonus
