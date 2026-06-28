# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vigomes- <vigomes-@student.42sp.org.br>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/31 10:44:34 by vigomes-          #+#    #+#              #
#    Updated: 2026/06/28 14:17:10 by vigomes-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME			=	push_swap
CC				=	cc
MAKEFLAGS		=	--silent
RM				=	rm -rf

H_DIR			=	includes/
LIBFT_DIR		=	includes/libft/
LIBFT			=	$(LIBFT_DIR)libft.a

MAIN_DIR		=	src/main/
PARSING_DIR		=	src/parsing/
STACK_DIR		=	src/stack/
INDEX_DIR		=	src/index/
SLC_DIR			=	src/selector/
SLC_UDIR		=	$(SLC_DIR)_disorder_calculator/
OPS_DIR			=	src/operations/
ALG_DIR			=	src/algorithms/

MAIN_H			=	push_swap.h
PARSING_H		=	$(PARSING_DIR)parsing.h
STACK_H			=	$(STACK_DIR)stack.h
INDEX_H			=	$(INDEX_DIR)index.h
SLC_H			=	$(SLC_DIR)selector.h
OPS_H			=	$(OPS_DIR)operations.h
ALG_H			=	$(ALG_DIR)algorithms.h
HEADERS			=	$(H_DIR)$(MAIN_H) $(PARSING_H) $(STACK_H)  $(SLC_H) $(INDEX_H) $(OPS_H) $(ALG_H)

MAIN_SRC		=	main.c
PARSING_SRCS	=	errors.c parse_args.c validate_args.c
STACK_SRCS		=	stack_check.c stack_create.c stack_utils.c
INDEX_SRC		=	index.c
SLC_SRCS		=	selector.c
SLC_UTILS		=	disorder_calculator.c
OPS_SRCS		=	swap.c push.c rotate.c reverse_rotate.c
ALG_SRCS		=	n_squared.c n_root.c n_log.c

ALL_SRCS		=	$(addprefix $(MAIN_DIR), $(MAIN_SRC)) \
					$(addprefix $(PARSING_DIR), $(PARSING_SRCS)) \
					$(addprefix $(STACK_DIR), $(STACK_SRCS)) \
					$(addprefix $(INDEX_DIR), $(INDEX_SRC)) \
					$(addprefix $(SLC_DIR), $(SLC_SRCS)) \
					$(addprefix $(SLC_UDIR), $(SLC_UTILS)) \
					$(addprefix $(OPS_DIR), $(OPS_SRCS)) \
					$(addprefix $(ALG_DIR), $(ALG_SRCS))

CFLAGS			=	-Wall -Wextra -Werror -I $(H_DIR) -I $(LIBFT_DIR) \
					-I $(PARSING_DIR) -I $(STACK_DIR) -I $(INDEX_DIR) \
					-I $(SLC_DIR) -I $(OPS_DIR) -I $(ALG_DIR)

OBJ_DIR			=	build/
OBJS			=	$(addprefix $(OBJ_DIR), $(MAIN_SRC:.c=.o) $(PARSING_SRCS:.c=.o) $(STACK_SRCS:.c=.o) $(INDEX_SRC:.c=.o) $(SLC_SRCS:.c=.o) $(SLC_UTILS:.c=.o) $(OPS_SRCS:.c=.o) $(ALG_SRCS:.c=.o))

ALL_FILES		=	$(LIBFT_DIR)*.c $(LIBFT_DIR)*.h $(ALL_SRCS)

PROGRAM			=	"PUSH SWAP"
EXEC_NAME		=	"push_swap"

DEFAULT			=	\033[0m
RED				=	\033[1;31m
CYAN			=	\033[1;36m
PINK			=	\033[1;35m
GREEN			=	\033[1;32m
YELLOW			=	\033[1;33m
REWHITE			=	\033[1;7;97m
RECYAN			=	\033[1;7;36m
REPINK			=	\033[1;7;35m
RERED			=	\033[1;7;31m
REGREEN			=	\033[1;7;32m
REYELLOW		=	\033[1;7;33m

TOTAL_FILES		=	$(words $(OBJS))
COMPLETED		=	0

define update_progress
		@if [ "$(COMPLETED)" -eq "0" ]; then \
			clear; \
		fi
		@$(eval COMPLETED=$(shell echo $$(($(COMPLETED)+1))))
		@$(eval PERCENT=$(shell echo $$(($(COMPLETED)*100/$(TOTAL_FILES)))))
		@$(eval FILLED=$(shell echo $$(($(PERCENT)*20/100))))
		@$(eval EMPTY=$(shell echo $$((20-$(FILLED)))))
		@clear
		@printf "$(YELLOW)COMPILING $(PROGRAM)! \n"
		@for i in $$(seq 1 $(FILLED)); do printf "🟧"; done
		@for i in $$(seq 1 $(EMPTY)); do printf "  "; done
		@printf "%d%%$(DEFAULT)" $(PERCENT)
		@if [ "$(COMPLETED)" -eq "$(TOTAL_FILES)" ]; then \
			clear; \
			echo "${GREEN}$(PROGRAM) COMPILED!"; \
			echo "🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩🟩 100%${DEFAULT}"; \
		fi
endef

all: $(NAME)

$(NAME): $(LIBFT) $(OBJS)
		$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)
		@echo "$(PROGRAM) created as $(EXEC_NAME)"

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(OBJ_DIR)%.o: %.c $(HEADERS)
			@clear
			@mkdir -p $(OBJ_DIR)
			$(CC) $(CFLAGS) -c $< -o $@
			@$(call update_progress)

vpath %.c $(MAIN_DIR) $(PARSING_DIR) $(STACK_DIR) $(INDEX_DIR) $(SLC_DIR) $(SLC_UDIR) $(OPS_DIR) $(ALG_DIR)

norm:
		@for file in $(ALL_FILES); do \
			if norminette $$file | grep -q "Error"; then \
				echo "$(RED)❌ $$file$(DEFAULT)"; \
			else \
				echo "$(GREEN)✅ $$file$(DEFAULT)"; \
			fi; \
		done
		-@norminette > norminette.log 2>&1
		@echo "$(CYAN)🆗 Norminette check complete! 🆗$(DEFAULT)"
		@echo "$(CYAN)Norminette report saved in norminette.log!$(DEFAULT)"

clean:
		$(RM) $(OBJ_DIR)

fclean: clean
		$(RM) $(NAME)
		$(RM) norminette.log
		@$(MAKE) fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re norm