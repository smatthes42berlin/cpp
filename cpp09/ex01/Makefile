# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: smatthes <smatthes@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/21 10:44:02 by smatthes          #+#    #+#              #
#    Updated: 2025/01/05 18:07:05 by smatthes         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CXX 		= c++
CXXFLAGS 	= -Werror -Wextra -Wall -Wpedantic -fsanitize=undefined -g -std=c++98
# CXXFLAGS 	= -Werror -Wextra -Wall -Wpedantic -fsanitize=address,undefined -g -std=c++98

TARGET 		= RPN
FILES 		= main RPN
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