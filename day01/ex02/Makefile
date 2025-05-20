# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/16 16:25:13 by kben-tou          #+#    #+#              #
#    Updated: 2025/05/16 21:52:54 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = this_is_brain
SRCS = main.cpp 

OBJS=$(SRCS:.cpp=.o)
CPPFLAGS=-Wall -Wextra -Werror

all: $(NAME)

%.o: %.cpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $< -o $@

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all