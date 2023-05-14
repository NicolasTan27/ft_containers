# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/06/06 15:29:50 by ntan              #+#    #+#              #
#    Updated: 2022/09/29 20:54:32 by ntan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# SRCS			=	test_reverse_iterator.cpp
# NAME			= 	test_reverse_iterator
# SRCS			=	test_enable_if.cpp
# NAME			=	test_enable_if
# SRCS			=	test_is_integral.cpp
# NAME			= 	test_is_integral
# SRCS			=	test_equal.cpp
# NAME			= 	test_equal
# SRCS			=	test_lexicographical_compare.cpp
# NAME			= 	test_lexicographical_compare
# SRCS			=	test_pair.cpp
# NAME			= 	test_pair
# SRCS			=	test_normal_iterator.cpp
# NAME			= 	test_normal_iterator
# SRCS			=	test_iterator.cpp
# NAME			= 	test_iterator
# SRCS			=	test_rb_tree.cpp
# NAME			= 	test_rb_tree
SRCS			=	test_binary_tree.cpp
NAME			= 	test_binary_tree

%.o:%.tpp
				$(CC) $(CFLAGS) -I. -c $< -o $@ -E

%.o:%.cpp
				$(CC) $(CFLAGS) -I. -c $< -o $@ -E

OBJS			= 	$(SRCS:.cpp=.o)

CC				= 	c++
RM				= 	rm -f
CFLAGS			= 	-Wall -Wextra -Werror -g -std=c++98

all:			$(NAME)

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -I. $(SRCS) -o $(NAME)

clean:
				$(RM) $(OBJS)

fclean:			
				$(RM) $(OBJS)
				$(RM) $(NAME)

re:				fclean all

	