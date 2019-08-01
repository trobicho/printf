CC = gcc
CFLAGS = -Wall -Wextra -Werror
SRCS = ft_printf.c convert_arg.c convert_arg_number.c convert_utils.c format.c format_utils.c cast.c littletoi.c float.c
HDRS = ft_printf.h convert_arg.h convert_utils.h format.h cast.h float.h
OUTS = $(SRCS:.c=.o)
NAME = libftprintf.a

all: $(NAME)

$(NAME): $(OUTS)
	ar sucr $(NAME) $(OUTS)

%.o : %.c
	$(CC) $(CFLAGS) -c $^

clean:
	rm -f $(OUTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re 
