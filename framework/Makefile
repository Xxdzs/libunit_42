#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: angagnie <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/01 21:38:47 by angagnie          #+#    #+#              #
#    Updated: 2018/12/01 21:44:47 by angagnie         ###   ########.fr        #
#                                                                              #
#******************************************************************************#

FILE=libunit.c
NAME=libunit.a

LINKER=ar -rcs
COMPILER=clang
FLAGS=-Wall -Wextra -Werror

OBJECT=${FILE:.c=.o}

$(NAME): $(OBJECT)
	$(LINKER) $^

$(OBJECT): $(FILE)
	$(COMPILER) $(FLAGS) -c $< -I ./
