# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 22:13:51 by kben-tou          #+#    #+#              #
#    Updated: 2025/05/16 22:56:17 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = weapon
SRCS = main.cpp \
		Weapon.cpp \
		HumanA.cpp \
		HumanB.cpp

OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp Weapon.hpp HumanA.hpp HumanB.hpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all