CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
SRCS = main.c ft_printf.c convert_arg.c convert_arg_number.c convert_utils.c format.c cast.c littletoi.c grisu.c
HDRS = ft_printf.h convert_arg.h convert_utils.h format.h cast.h grisu.h
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
