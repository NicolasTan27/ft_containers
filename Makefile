# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/24 18:27:04 by ntan              #+#    #+#              #
#    Updated: 2022/10/27 16:17:38 by ntan             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRCS			=	main.cpp
OBJS			= 	$(SRCS:.cpp=.o)

SRCS_SUB			=	main_sub.cpp
OBJS_SUB			= 	$(SRCS_SUB:.cpp=.o)

DEPENDS 		= 	$(patsubst %.cpp,%.d,$(SRCS))			
CC				=	c++
RM				=	rm -f
CFLAGS			=	-Wall -Wextra -Werror -g -std=c++98
NAME			=	ft_containers
NAME_SUB		= 	ft_containers_sub

all:			$(NAME)

%.o:%.tpp
				$(CC) $(CFLAGS) -I. -c $< -o $@ -E

%.o:%.cpp
				$(CC) $(CFLAGS) -MMD -MP -I. -c $< -o $@ -E

$(NAME):		$(OBJS)
				$(CC) $(CFLAGS) -I. $(SRCS) -o $(NAME)

-include $(DEPENDS)

sub:			$(NAME_SUB)
				
$(NAME_SUB):	$(OBJS_SUB)
				$(CC) $(CFLAGS) -I. $(SRCS_SUB) -o $(NAME_SUB) -D STD=1
				time -p ./$(NAME_SUB) 50
				time -p ./$(NAME_SUB) 42910
				time -p ./$(NAME_SUB) 45123543
				rm -f $(NAME_SUB)
				$(CC) $(CFLAGS) -I. $(SRCS_SUB) -o $(NAME_SUB) -D STD=0
				time -p ./$(NAME_SUB) 50
				time -p ./$(NAME_SUB) 42910
				time -p ./$(NAME_SUB) 45123543
				rm -f $(NAME_SUB) $(OBJS_SUB)
				rm -f main_sub.d

clean:
				$(RM) $(OBJS) $(DEPENDS)

fclean:
				$(RM) $(OBJS) $(DEPENDS)
				$(RM) $(NAME)

re:				fclean all
