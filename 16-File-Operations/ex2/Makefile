NAME = ft_tail
CC = cc
SOURCES = main.c \
          libft.c \
	  check.c \
	  read_error.c
OBJECTS = $(SOURCES:.c=.o)
CFLAGS = -Wall -Wextra -Werror
all: $(NAME)
$(NAME) : $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(NAME)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@
.PHONY: all clean fclean re
clean:
	rm -f $(OBJECTS)
fclean: clean
	rm -f $(NAME)
re: fclean all
