# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/08/01 18:57:17 by kben-tou          #+#    #+#              #
#    Updated: 2025/08/01 19:48:03 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = word_on_fire
SRCS = main.cpp \
		Animal.cpp \
		Cat.cpp \
		Dog.cpp \
		Brain.cpp

OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp Animal.hpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all