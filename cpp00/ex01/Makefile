CXX 		= c++
CXXFLAGS 	= -Werror -Wextra -Wall -std=c++98

TARGET 		= awesome_phonebook
FILES 		= PhoneBook Contact main
SRC			= $(FILES:=.cpp)
OBJ 		= $(SRC:.cpp=.o)


.PHONY: all clean fclean re

all: ${TARGET}

${TARGET}: ${OBJ}
	${CXX} ${CXXFLAGS} ${OBJ} -o ${TARGET}

%.o: %.cpp
	${CXX} $(CXXFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)


fclean: clean
	$(RM) $(TARGET)

re: fclean all