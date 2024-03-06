NAME = libft.a
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror
SRC_DIR = src/
FTLIBFT = $(SRC_DIR)libft_files/ft_isalpha.c \
					$(SRC_DIR)libft_files/ft_isdigit.c \
					$(SRC_DIR)libft_files/ft_isalnum.c \
					$(SRC_DIR)libft_files/ft_isascii.c \
					$(SRC_DIR)libft_files/ft_isprint.c \
      				$(SRC_DIR)libft_files/ft_strlen.c \
					$(SRC_DIR)libft_files/ft_memset.c \
					$(SRC_DIR)libft_files/ft_bzero.c \
					$(SRC_DIR)libft_files/ft_memcpy.c \
					$(SRC_DIR)libft_files/ft_memmove.c \
					$(SRC_DIR)libft_files/ft_strlcpy.c \
					$(SRC_DIR)libft_files/ft_strlcat.c \
					$(SRC_DIR)libft_files/ft_toupper.c \
					$(SRC_DIR)libft_files/ft_tolower.c \
					$(SRC_DIR)libft_files/ft_strchr.c \
					$(SRC_DIR)libft_files/ft_strrchr.c \
					$(SRC_DIR)libft_files/ft_strncmp.c \
					$(SRC_DIR)libft_files/ft_memchr.c \
					$(SRC_DIR)libft_files/ft_memcmp.c \
					$(SRC_DIR)libft_files/ft_strnstr.c \
					$(SRC_DIR)libft_files/ft_atoi.c \
					$(SRC_DIR)libft_files/ft_calloc.c \
					$(SRC_DIR)libft_files/ft_strdup.c \
					$(SRC_DIR)libft_files/ft_substr.c \
					$(SRC_DIR)libft_files/ft_strjoin.c \
					$(SRC_DIR)libft_files/ft_strtrim.c \
					$(SRC_DIR)libft_files/ft_split.c \
					$(SRC_DIR)libft_files/ft_itoa.c \
					$(SRC_DIR)libft_files/ft_strmapi.c \
					$(SRC_DIR)libft_files/ft_striteri.c \
					$(SRC_DIR)libft_files/ft_putchar_fd.c \
					$(SRC_DIR)libft_files/ft_putstr_fd.c \
					$(SRC_DIR)libft_files/ft_putendl_fd.c \
					$(SRC_DIR)libft_files/ft_putnbr_fd.c

FTLIBFTBONUS = $(SRC_DIR)libft_files/ft_lstnew_bonus.c \
					$(SRC_DIR)libft_files/ft_lstadd_front_bonus.c \
					$(SRC_DIR)libft_files/ft_lstsize_bonus.c \
					$(SRC_DIR)libft_files/ft_lstlast_bonus.c \
					$(SRC_DIR)libft_files/ft_lstadd_back_bonus.c \
					$(SRC_DIR)libft_files/ft_lstdelone_bonus.c \
					$(SRC_DIR)libft_files/ft_lstclear_bonus.c \
					$(SRC_DIR)libft_files/ft_lstiter_bonus.c \
					$(SRC_DIR)libft_files/ft_lstmap_bonus.c

FTPRINTF_DIR = $(SRC_DIR)ft_printf/ft_format_check.c \
					$(SRC_DIR)ft_printf/ft_print_char.c \
					$(SRC_DIR)ft_printf/ft_print_decimal.c \
					$(SRC_DIR)ft_printf/ft_print_hex_lower.c \
					$(SRC_DIR)ft_printf/ft_print_hex_upper.c \
					$(SRC_DIR)ft_printf/ft_print_ptr.c \
					$(SRC_DIR)ft_printf/ft_print_str.c \
					$(SRC_DIR)ft_printf/ft_print_unsigned_decimal.c \
					$(SRC_DIR)ft_printf/ft_printf.c

GNL_DIR = $(SRC_DIR)gnl_files/get_next_line.c \
					$(SRC_DIR)gnl_files/get_next_line_utils.c

GNL_BONUS_DIR = $(SRC_DIR)gnl_files/get_next_line_bonus.c \
					$(SRC_DIR)gnl_files/get_next_line_utils_bonus.c

SRC = $(FTLIBFT) $(FTLIBFTBONUS) $(FTPRINTF_DIR) \
		$(GNL_DIR) $(GNL_BONUS_DIR)

OBJ = $(SRC:.c=.o)
BONUS_OBJ = $(FTLIBFTBONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	@echo "\033[0;32m" ---------Building libft-------- "\033[0m"
	@ar rcs $(NAME) $(OBJ)

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@

bonus: .bonus

.bonus: $(BONUS_OBJ) 
	@ar rcs $(NAME) $(BONUS_OBJ)
	@touch .bonus

clean:
	@echo "\033[0;32m" --cleaning libft object files-- "\033[0m"
	@rm -f $(OBJ) $(BONUS_OBJ)

fclean: clean
	@echo "\033[0;32m" -----removing libft files------ "\033[0m"
	@rm -f $(NAME)
	@rm -f .bonus

re: fclean all

.PHONY: all clean fclean re bonus
