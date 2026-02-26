NAME = btc
SRCS = main.cpp \
		BitcoinExchange.cpp

OBJS = $(SRCS:.cpp=.o)
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -fsanitize=address

all: $(NAME)

%.o: %.cpp BitcoinExchange.hpp
	c++ $(CPPFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	c++ $(CPPFLAGS) $(OBJS) -o $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -rf $(NAME)

re: fclean all
