# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rodro <rodro@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/04 16:24:11 by rofuente          #+#    #+#              #
#    Updated: 2023/05/05 16:19:00 by rodro            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

LIB	=	ar rcs
RM	=	rm -f

CC	=	gcc
CFLAGS	=	-Wall -Wextra -Werror -I ./include -I ./libft/include/ -I ./mlx/
DEBUG	=	-g3 -fsanitize=address

NAME	=	so_long

SS	=	so_long.c read_map.c ft_messeg.c check_map.c check_path.c
UTILS	=	ft_no_nl.c ft_slen.c

SRC_DIR	=	./src/
SRCU_DIR = ./utils/
SRCS	=	$(addprefix $(SRC_DIR), $(SS))

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(SS:.c=.o) $(UTILS:.c=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

LIBFT_PATH = libft/
LIBFT = $(LIBFT_PATH)libft.a

MLX_PATH = mlx/
MLX = $(MLX_PATH)libmlx.a
#INCLUDE = include/

##########COLORES##########
DEF_COLOR = \033[0;39m
CUT = \033[K
R = \033[31;1m
G = \033[32;1m
Y = \033[33;1m
B = \033[34;1m
P = \033[35;1m
GR = \033[30;1m
END = \033[0m

##########REGLAS##########
all: $(OBJ_DIR) $(NAME)

$(LIBFT) : $(LIBFT_PATH)
	@make -C $(LIBFT_PATH)

$(MLX) : $(MLX_PATH)
	@make -C $(MLX_PATH)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRCU_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) $(MLX) -o $(NAME)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	$(RM) $(OBJ)
	@make clean -C libft
	@rm -rf $(OBJ_DIR)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	$(RM) $(NAME)
	@make fclean -C libft
	@rm -f $(OBJ_DIR)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
