# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: msakwins <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/08/12 20:08:21 by msakwins          #+#    #+#              #
#    Updated: 2017/08/29 20:10:14 by msakwins         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = msakwins.filler

FLAGS = -Wall -Wextra -Werror
	
LIBFTA = libft.a

LIBFTDIR = ./libft
OBJDIR = ./obj/
INCDIR = ./includes
SRCDIR = ./srcs/

SRCS_NAME = filler.c \
			parse.c \
			parse_tab.c \
			utils.c \
			touchi.c \

OBJS = $(addprefix $(OBJDIR),$(SRCS_NAME:.c=.o))
LIBFT = $(addprefix $(LIBFTDIR)/,$(LIBFTA))

GREEN = \033[0;32m
RED = \033[0;31m
NC = \033[0m

SRCS = $(addprefix $(SRCDIR),$(SRCS_NAME))

all: $(NAME)

obj:
		@mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
		@gcc $(FLAGS) -I $(INCDIR) -I $(LIBFTDIR) -o $@ -c $<

$(LIBFT):
		@make -C $(LIBFTDIR)

$(NAME): $(LIBFT) obj $(OBJS)
		@gcc $(OBJS) $(LIBFT) -lm -o $(NAME)
			@echo "$(GREEN)---------filler compiled---------$(NC)"

norme:
		@norminette includes srcs

clean:
		@rm -rf $(OBJDIR)
		@make clean -C $(LIBFTDIR)

fclean:	clean
		@rm -f $(NAME)
		@make fclean -C $(LIBFTDIR)
		@echo "$(GREEN)----filler removed completely----$(NC)"

re: fclean all
