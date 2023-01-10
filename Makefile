# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sfathima <sfathima@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/22 10:40:34 by sfathima          #+#    #+#              #
#    Updated: 2023/01/10 15:16:39 by sfathima         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


CXX			=	c++
CPPFLAGS	=	-std=c++98 -g3 -Wall -Wextra -Werror
NS_STD		=	-D NAMESPACE=std
NS_FT		=	-D NAMESPACE=ft
DELETE		=	rm -rf

INC_DIR		=	include
SRC_DIR		=	sources
OBJ_DIR		=	test_reports


#####################################################################################

V_DIR		=	vector_tests
STD_V_DIR	=	std_vector
FT_V_DIR	=	ft_vector

V_TEST	=	constructors.cpp iterators.cpp capacity.cpp element_access.cpp  modifiers.cpp relational.cpp swap.cpp

STD_V_OBJ	=	$(addprefix $(OBJ_DIR)/$(STD_V_DIR)/, $(V_TEST:%cpp=%o))
FT_V_OBJ	=	$(addprefix $(OBJ_DIR)/$(FT_V_DIR)/, $(V_TEST:%cpp=%o))

$(OBJ_DIR)/$(FT_V_DIR)/%.o : $(SRC_DIR)/$(V_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_V_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_FT) -c $< -o $@

$(OBJ_DIR)/$(STD_V_DIR)/%.o : $(SRC_DIR)/$(V_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_V_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_STD)  -c $< -o $@

#####################################################################################

STK_DIR		=	stack_tests
STD_STK_DIR	=	std_stack
FT_STK_DIR	=	ft_stack

STK_TEST	=	modifiers.cpp capacity.cpp relational.cpp

STD_STK_OBJ	=	$(addprefix $(OBJ_DIR)/$(STD_STK_DIR)/, $(STK_TEST:%cpp=%o))
FT_STK_OBJ	=	$(addprefix $(OBJ_DIR)/$(FT_STK_DIR)/, $(STK_TEST:%cpp=%o))

$(OBJ_DIR)/$(STD_STK_DIR)/%.o : $(SRC_DIR)/$(STK_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(STD_STK_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_STD)  -c $< -o $@

$(OBJ_DIR)/$(FT_STK_DIR)/%.o : $(SRC_DIR)/$(STK_DIR)/%.cpp
			@mkdir -p $(OBJ_DIR) && mkdir -p $(OBJ_DIR)/$(FT_STK_DIR)
			@$(CXX) $(CPPFLAGS) $(NS_FT) -c $< -o $@

#####################################################################################

vector:		$(STD_V_OBJ) $(FT_V_OBJ)
stack:		$(STD_STK_OBJ) $(FT_STK_OBJ)

clean:
			@$(DELETE) $(OBJ_DIR) *.log

fclean:		clean

re:			fclean all

.PHONY:		vector map stack clean fclean re