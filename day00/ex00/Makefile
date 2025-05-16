# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/09 23:17:20 by kben-tou          #+#    #+#              #
#    Updated: 2025/05/14 20:53:22 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Megaphone
SRC = megaphone.cpp
OBJ = megaphone.o

CPPFLAGS = -Wall -Wextra -Werror -std=c++98
all: $(NAME)

$(OBJ): $(SRC)
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJ)
	c++ $(CPPFLAGS) $(OBJ) -o $(NAME)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all