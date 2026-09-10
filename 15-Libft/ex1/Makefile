NAME = libft.a
CC = cc
SOURCES = srcs/ft_putchar.c \
	  srcs/ft_swap.c \
	  srcs/ft_putstr.c \
	  srcs/ft_strlen.c \
	  srcs/ft_strcmp.c \
	  main.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -Iincludes -c $< -o $@
.PHONY: all clean fclean re
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
