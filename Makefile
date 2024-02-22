# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: cavan-vl <cavan-vl@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2024/02/12 15:49:22 by cavan-vl      #+#    #+#                  #
#    Updated: 2024/02/22 16:17:35 by cavan-vl      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME			:= so_long

LIBMLX			:= ./libraries/MLX42
LIBFT			:= ./libraries/libft42

CFLAGS			:= -Wall -Werror -Wextra
CC				:= cc -Ofast
LIBS			:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
HEADER			:= -I ./includes -I $(LIBMLX)/include -I $(LIBFT)

SRCS			:= main.c parse_map.c

SRC_DIR			:= src
SRC				:= $(addprefix $(SRC_DIR)/, $(SRCS))

OBJ_DIR			:= obj
OBJ				:= $(addprefix $(OBJ_DIR)/, $(notdir $(SRC:.c=.o)))

#	====	COLORS!		====	#
BLACK		:=	\033[30m
RED			:=	\033[31m
GREEN		:=	\033[32m
YELLOW		:=	\033[33m
BLUE		:=	\033[34m
MAGENTA		:=	\033[35m
CYAN		:=	\033[36m
WHITE		:=	\033[37m
RESET		:=	\033[0m

#	====	COLORS! (but the bold kind)		====	#
BLACKB		:=	\033[1;30m
REDB		:=	\033[1;31m
GREENB		:=	\033[1;32m
YELLOWB		:=	\033[1;33m
BLUEB		:=	\033[1;34m
MAGENTAB	:=	\033[1;35m
CYANB		:=	\033[1;36m
WHITEB		:=	\033[1;37m

all: libmlx libft $(NAME)

libmlx:
	@ cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

libft:
	@ make -C $(LIBFT)

submodule:
	@ git submodule update --init --recursive

$(NAME): $(OBJ)
	@ $(CC) $^ $(CFLAGS) $(HEADER) $(LIBS) -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@ mkdir -p $(OBJ_DIR)
	@ $(CC) $(CFLAGS) $(HEADER) -c $< -o $@

clean:
	@ rm -rf $(OBJ_DIR)

fclean: clean
	@ rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re libmlx
