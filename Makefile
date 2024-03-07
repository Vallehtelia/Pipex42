NAME = pipex
LIBFT = ./libft
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC_DIR = ./src/

SRC_FILES = pipex.c pipex_utils.c parsing.c

SRC = $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJ = $(SRC:.c=.o)

all: $(LIBFT)/libft.a $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m" ---------Building pipex-------- "\033[0m"
	@$(CC) $(OBJ) -o $(NAME) -L$(LIBFT) -lft

$(LIBFT)/libft.a:
	@make -C $(LIBFT)
	@make bonus -C $(LIBFT)

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS)

clean:
	@echo "\033[0;32m" ------------Cleaning----------- "\033[0m"
	@rm -f $(OBJ)
	@make clean -C $(LIBFT)

fclean: clean
	@echo "\033[0;32m" ---------Deep cleaning--------- "\033[0m"
	@rm -f $(NAME)
	@$(RM) $(LIBFT)/libft.a

re: fclean all

.PHONY: all clean fclean re
