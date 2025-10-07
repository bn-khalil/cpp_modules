# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kben-tou <kben-tou@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/10/07 18:28:45 by kben-tou          #+#    #+#              #
#    Updated: 2025/10/07 18:28:46 by kben-tou         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Identify_real_type
SRCS = main.cpp \
		Base.cpp \
		DrivedA.cpp \
		DrivedB.cpp \
		DrivedC.cpp \
		Utils.cpp

OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98

all: $(NAME)

%.o: %.cpp DrivedA.hpp DrivedB.hpp DrivedC.hpp Base.hpp Utils.hpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
