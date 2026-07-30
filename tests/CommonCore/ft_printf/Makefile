ROOT		= ../../..
PRINTF_DIR	= $(ROOT)/src/CommonCore/ft_printf
LIBFT_DIR	= $(ROOT)/src/CommonCore/libft

NAME		= test_ft_printf.out
CC			= cc
CFLAGS		= -Wall -Wextra -Werror -Wno-format-zero-length -Wno-format-overflow

all: $(NAME)

$(NAME): test_ft_printf.c
	$(MAKE) -C $(PRINTF_DIR)
	$(CC) $(CFLAGS) -I $(PRINTF_DIR)/include -I $(LIBFT_DIR)/include \
		-o $(NAME) test_ft_printf.c \
		-L $(PRINTF_DIR)/bin -lftprintf \
		-L $(LIBFT_DIR)/bin -lft

clean:
	rm -f $(NAME)

fclean: clean

re: fclean all

test: $(NAME)
	./$(NAME)

.PHONY: all clean fclean re test
