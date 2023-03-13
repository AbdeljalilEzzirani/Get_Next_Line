# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: abez-zir <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/13 13:25:02 by abez-zir          #+#    #+#              #
#    Updated: 2023/03/13 13:53:18 by abez-zir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line

SOURCES = get_next_line.c get_next_line_utils.c

OBJ = $(SOURCES:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $^

%.o:%.c get_next_line.h
	$(CC) $(CFLAGS) -c $< -o $@

clean : 
	rm -rf $(OBJ)

fclean : clean
	rm  -rf $(NAME)

re : fclean all
