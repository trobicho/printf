CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
SRCS = main.c ft_printf.c convert_arg.c convert_utils.c format.c
HDRS = ft_printf.h convert_arg.h convert_utils.h format.h
OUTS = $(SRCS:.c=.o)
NAME = ft_printf

all: $(NAME)

$(NAME): $(OUTS)
	$(CC) $(OUTS) -o $(NAME)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
