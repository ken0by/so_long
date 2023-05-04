LIB = ar rcs
RM = rm -f

CC = gcc
CFLAGS = -Wall -Wextra -Werror -I ./include -I ./ft_printf/include -I ./gnl/include

NAME = libft.a

FT_PRINTF	=	ft_printf.c ft_print_char.c ft_print_nbr.c
GNL	=	get_next_line.c get_next_line_bonus.c get_next_line_utils.c get_next_line_utils_bonus.c


SRC6_DIR	=	./ft_printf/src/
SRC7_DIR	=	./gnl/src/

SRC6	=	$(addprefix $(SRC6_DIR), $(FT_PRINTF))
SRC7	=	$(addprefix $(SRC7_DIR), $(GNL))

OBJ_DIR	=	./obj/
OBJ_FILES	=	$(FT_PRINTF:.c=.o) $(GNL:.c=.o)
OBJ	=	$(addprefix $(OBJ_DIR), $(OBJ_FILES))

all: $(OBJ_DIR) $(NAME)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)
$(OBJ_DIR)%.o:$(SRC6_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@
$(OBJ_DIR)%.o:$(SRC7_DIR)%.c
	$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

$(NAME): $(OBJ)
	$(LIB) $(NAME) $(OBJ)
	@echo "\n$(G)Basic library compiled!$(DEF_COLOR)-> $@\n"

clean:
	$(RM) $(OBJ)
	@rm -rf $(OBJ_DIR)
	@echo "$(R)All .o files removed$(DEF_COLOR)\n"

fclean: clean
	$(RM) $(NAME)
	@rm -rf $(OBJ_DIR)
	@echo "$(R)Library .a file removed$(DEF_COLOR)\n"

re: fclean all

.PHONY: all clean fclean re
