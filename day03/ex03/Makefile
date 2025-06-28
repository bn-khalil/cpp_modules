# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/06/18 11:13:45 by kben-tou          #+#    #+#              #
#    Updated: 2025/06/27 19:56:20 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = DiamondTrap
SRCS = main.cpp \
		ClapTrap.cpp \
		ScavTrap.cpp \
		FragTrap.cpp \
		DiamondTrap.cpp \

OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all