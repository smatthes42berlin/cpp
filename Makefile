CXX 		= c++
# CXXFLAGS 	= -Werror -Wextra -Wall -std=c++98
CXXFLAGS 	= -std=c++98

TARGET 		= test
FILES 		= test
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