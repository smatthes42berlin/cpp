# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 10:44:12 by smatthes          #+#    #+#              #
#    Updated: 2024/07/21 15:12:08 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Werror -Wextra -Wall -std=c++98

TARGET 		= replacer
FILES 		= main Replacer
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