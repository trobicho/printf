CC = gcc
#CFLAGS = -Wall -Wextra -Werror
CFLAGS = -g
SRCS = ft_printf.c convert_arg.c convert_arg_number.c convert_utils.c format.c format_utils.c cast.c littletoi.c float.c
HDRS = ft_printf.h convert_arg.h convert_utils.h format.h cast.h float.h
OUTS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OUTS)
	ar sucr $(NAME) $(OUTS)

test: $(OUTS) main.c
	$(CC) main.c -L ./ -lftprintf -o test

frank_test: $(OUTS) franck_test.c
	$(CC) franck_test.c -L ./ -lftprintf -o test

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
