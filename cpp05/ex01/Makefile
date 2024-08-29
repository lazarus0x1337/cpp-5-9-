NAME = Bureaucrat
SRC = Bureaucrat.cpp Form.cpp main.cpp 
OBJ = $(SRC:.cpp=.o)
CXX = c++
CPPFLAGS = -std=c++98 -Wall -Wextra -Werror

all :$(NAME)

$(NAME) : $(OBJ)
	$(CXX) $(CPPFLAGS) $(OBJ) -o $(NAME)

clean :
		rm -f $(OBJ)
fclean : clean
		rm -f $(NAME)
re : fclean $(NAME)