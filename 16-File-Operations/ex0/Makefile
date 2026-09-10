NAME = ft_display_file
CC = cc
SOURCES = main.c
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
