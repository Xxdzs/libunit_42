#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 21:38:47 by angagnie          #+#    #+#              #
#    Updated: 2018/12/02 15:23:37 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FILE=libunit.c
NAME=libunit.a
LIBFT_PATH=../libft

LINKER=ar rcs
COMPILER=clang
IFLAGS=$(addprefix -I ,./ $(LIBFT_PATH)/include)
FLAGS=-Wall -Wextra -Werror $(IFLAGS)

OBJECT=${FILE:.c=.o}

all: $(NAME)

re: fclean all

$(NAME): $(OBJECT)
	$(LINKER) $@ $^

$(OBJECT): $(FILE)
	$(COMPILER) $(FLAGS) -c $<

clean:
	rm -f $(OBJECT)

fclean: clean
	rm -f $(NAME)
