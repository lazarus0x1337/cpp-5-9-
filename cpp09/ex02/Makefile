NAME = PmergeMe
SRC =  PmergeMe.cpp main.cpp
OBJ = $(SRC:.cpp=.o)
CXX = c++
CPPFLAGS =  -Wall -Wextra -Werror

all :$(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)
re : fclean $(NAME)