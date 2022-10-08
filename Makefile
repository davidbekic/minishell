# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dbekic <dbekic@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/05 13:42:29 by irifarac          #+#    #+#              #
#    Updated: 2022/10/07 17:13:18 by dbekic           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#Colores
RED = \033[0;31m
GREEN = \033[0;32m
RESET = \033[0m

NAME = minishell
CFLAGS = -Wall -Werror -Wextra -MMD

# Folders
OBJDIR = obj
SRCDIR = ./
EXECDIC = srcs/exec

# Files
LIBFT = Libft
# SRCDIR =	src/parser/main.c \
# 	  src/parser/ft_utils.c \
# 	  src/parser/ft_build.c \
# 	  src/parser/ft_parser.c \
# 	  src/parser/ft_termination.c \
# 	  src/parser/ft_exec.c  \
# 	  src/commands/echo.c    \
# 	  src/commands/env.c    \
# 	  src/commands/export.c    \
# 	  src/commands/pwd.c     \
# 	  src/commands/unset.c    \
# 	  src/env/ft_create_elem.c    \
# 	  src/env/ft_expand.c    \
# 	  src/env/ft_find_elem.c    \
# 	  src/env/ft_find_key_value.c    \
# 	  src/env/ft_free_env.c    \
# 	  src/env/ft_init_env.c    \
# 	  src/env/ft_var_name_check.c    \
# 	  src/exec/ft_execve.c    \
# 	  src/parser/prompt_parser.c    

SRC = srcs/parser/main.c \
	  srcs/parser/ft_utils.c \
	  srcs/parser/ft_build.c \
	  srcs/parser/ft_parser.c \
	  srcs/parser/ft_termination.c \
	  srcs/parser/ft_exec.c    \
	  srcs/parser/ft_prompt_parser.c \
	  srcs/parser/ft_builtin_parser.c \
	  srcs/parser/ft_quotes.c \
	  srcs/commands/echo.c    \
	  srcs/commands/env.c    \
	  srcs/commands/export.c    \
	  srcs/commands/pwd.c     \
	  srcs/commands/unset.c    \
	  srcs/commands/cd.c    \
	  srcs/env/ft_create_elem.c    \
	  srcs/env/ft_expand.c    \
	  srcs/env/ft_find_elem.c    \
	  srcs/env/ft_find_key_value.c    \
	  srcs/env/ft_free_env.c    \
	  srcs/env/ft_init_env.c    \
	  srcs/env/ft_var_name_check.c    \
	  srcs/exec/ft_execve.c    

OBJ = $(SRC:%.c=$(OBJDIR)/%.o)
# OBJ = $(patsubst %.c, %.o, $(SRC))

DEPENDS = $(patsubst %.c, %.d, $(SRC))

all: makelibs $(NAME)

makelibs:
	@$(MAKE) -C $(LIBFT)

#incluir dependencias
-include $(DEPENDS)
$(NAME): $(OBJ)
	@echo "$(GREEN)Creando ejecutable 🛠 $@ $(RESET)"
	gcc $(CFLAGS) $(SRC) -LLibft -lft -lreadline -o $@
	@rm -f minishell.d
	@echo "$(GREEN)Compilado ✅ $@ $(RESET)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "$(GREEN)Compilando $< de $@ $(RESET)"
	@mkdir -p $(@D)
	gcc $(CFLAGS) -o $@ -c $<

clean:

	rm -rf ./obj
	rm -rf minishell
	@make fclean -C $(LIBFT)

# ifneq ("$(wildcard $(OBJ) $(DEPENDS) $(OBJDIR))", "")
# 	rm -f $(OBJ) $(DEPENDS)
# 	rm -rf $(OBJDIR)
# 	@echo "$(GREEN)Borrando objetos de $(LIBFT)⚠️ $(RESET)"
# 	@make clean -C $(LIBFT)
# 	@echo "$(GREEN)Objetos borrados$(RESET)"
# else
# 	rm Libft/*.d 
# 	@echo "$(RED)Los objetos no existen, no se borra$(RESET)"
# endif

fclean: clean
# ifneq ("$(wildcard $(NAME))", "")
# 	rm -f $(NAME)
# 	@make fclean -C $(LIBFT)
# 	@echo "$(GREEN)Ejecutables borrados$(RESET)"
# else
# 	@echo "$(RED)Los ejecutables no existen, no se borra$(RESET)"
# endif

re: fclean all

.PHONY: all clean fclean re

