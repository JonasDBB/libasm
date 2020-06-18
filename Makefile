# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: jbennink <jbennink@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2020/06/10 14:57:33 by jbennink      #+#    #+#                  #
#    Updated: 2020/06/18 13:16:39 by jbennink      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = libasm.a

FLAGS = -Wall -Wextra -Werror

MAIN = main.c

SRCS = ft_strlen.s \
ft_strcpy.s \
ft_strcmp.s \
ft_write.s \
ft_read.s \
ft_strdup.s

OBJS = $(SRCS:.s=.o)

all: $(NAME)

%.o: %.s
	nasm -fmacho64 $<

$(NAME): $(OBJS)
	ar rcs $(NAME) $^

test: $(NAME) $(MAIN) $(OBJS)
	gcc $(MAIN) -L. -lasm -o test
# NOT USING FLAGS RIGHT NOW -L. -lasm

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)
	rm -f test

re: fclean all
