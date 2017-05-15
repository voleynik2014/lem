# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: voliynik <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/01/26 16:30:03 by voliynik          #+#    #+#              #
#    Updated: 2017/05/15 21:09:39 by voliynik         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = Lem_in
NAMELIB = libft.a

SRC	=	ft_build_new_way.c	\
		ft_calc_optimal_way.c	\
		ft_delete_lemin_things.c	\
		ft_realloc_lemin.c		\
		ft_validation.c		\
		permutation.c		\
		some_calc.c			\
		ft_lem_in.c 		\
		ft_read.c			\
		ft_print_result.c	\
		ft_create.c			
OBJ		= $(addprefix $(OBJDIR), $(SRC:.c=.o))

CC		= gcc
CFLAGS  = -Wall -Wextra -Werror
RM 		= rm -f

LIBDIR  = ./libft/
SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj $(NAME)

obj:
	@mkdir -p $(OBJDIR)
	@echo "creating dir: obj/"
	@mkdir -p $(LIBDIR)
	@echo "creating dir: libft/"
	@printf "\x1b[33mCreating project:\x1b[0m"

$(OBJDIR)%.o: $(SRCDIR)%.c
	@$(CC)  $(CFLAGS)  -I $(INCDIR) -c $< -o $@ 
	@printf '\033[0;34m[\033[0;32m✔\033[0;34m]\033[0m' 

$(NAME): $(NAMELIB) $(OBJ)
	@$(CC) -o $(NAME) $(OBJ) -L. -lft
	@echo "\n\x1b[32mLem-in has been created\x1b[0m"

$(NAMELIB):
	@cd $(LIBDIR); make; make clean; mv $(NAMELIB) ../;
	@printf '\n'

clean:
	@echo "Delete old obj"
	@rm -rf $(OBJDIR)

fclean: clean
	@$(RM) $(NAME) $(NAMELIB)

re: fclean all
