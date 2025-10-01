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
