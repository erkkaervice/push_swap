# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: eala-lah <eala-lah@student.hive.fi>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/04 15:36:34 by eala-lah          #+#    #+#              #
#    Updated: 2024/12/05 17:20:26 by eala-lah         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME          = push_swap
NAME_CHECKER  = checker
INCS          = -I ./inc/ -I ./libft/inc/
LIBFT_DIR     = libft/
LIBFT         = $(LIBFT_DIR)/libft.a

SRC_DIR       = src/
SRC           = \
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

SRC_CHECKER   = \
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

OBJ_DIR       = obj/
OBJS          = $(addprefix $(OBJ_DIR), $(SRC:.c=.o))
OBJS_CHECKER  = $(addprefix $(OBJ_DIR), $(SRC_CHECKER:.c=.o))

CC           = gcc
CFLAGS       = -Wall -Wextra -Werror $(INCS) -fPIC
GIT_FLAGS    = git clone --depth 1

all: $(LIBFT) $(OBJ_DIR) $(NAME) $(NAME_CHECKER)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR) 2> /dev/null || { echo "Failed to create object directory." >&2; exit 1; }

$(LIBFT):
	@if [ ! -d "$(LIBFT_DIR)" ]; then \
		$(GIT_FLAGS) https://github.com/erkkaervice/libft.git $(LIBFT_DIR) > /dev/null 2>&1 || { echo "Failed to clone libft repository." >&2; exit 1; }; \
	fi
	@make -C $(LIBFT_DIR) CFLAGS="-Wall -Wextra -Werror -fPIC -I ./inc/" > /dev/null 2>&1 || { echo "Failed to build libft library." >&2; exit 1; }
	@rm -f $(LIBFT_DIR)/README.md > /dev/null 2>&1 || { echo "Failed to remove README.md." >&2; exit 1; }

$(OBJ_DIR)%.o: $(SRC_DIR)%.c inc/push_swap.h
	@$(CC) $(CFLAGS) $(INCS) -c $< -o $@ 2> /dev/stderr || { echo "Failed to compile $<." >&2; exit 1; }

$(NAME): $(OBJS)
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) -L $(LIBFT_DIR) -lft 2> /dev/stderr || { echo "Failed to create executable $(NAME)." >&2; exit 1; }

$(NAME_CHECKER): $(OBJS_CHECKER)
	@$(CC) $(CFLAGS) $(OBJS_CHECKER) -o $(NAME_CHECKER) -L $(LIBFT_DIR) -lft 2> /dev/stderr || { echo "Failed to create executable $(NAME_CHECKER)." >&2; exit 1; }

bonus: all

clean:
	@rm -rf $(OBJ_DIR) 2> /dev/null || { echo "Failed to clean object files." >&2; exit 1; }
	@make -C $(LIBFT_DIR) clean > /dev/null 2>&1 || { if [ -d "$(LIBFT_DIR)" ]; then echo "Failed to clean libft." >&2; exit 1; fi; }

fclean: clean
	@rm -f $(LIBFT) $(NAME) $(NAME_CHECKER) 2> /dev/stderr || { echo "Failed to remove generated files." >&2; exit 1; }
	@rm -rf $(LIBFT_DIR) 2> /dev/stderr || { if [ -d "$(LIBFT_DIR)" ]; then echo "Failed to remove libft directory." >&2; exit 1; fi; }

re: fclean all

.PHONY: all clean fclean re bonus
