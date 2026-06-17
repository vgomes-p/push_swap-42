# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: danda-si <danda-si@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/05/31 10:44:34 by vigomes-          #+#    #+#              #
#    Updated: 2026/06/12 11:05:28 by danda-si         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	push_swap
CC			=	cc
MAKEFLAGS	=	--silent
AR			=	ar -rcs
RM			=	rm -rf

H_DIR		= includes/
LIBFT_DIR	=	includes/libft/
LIBFT		=	$(LIBFT_DIR)libft.a

CFLAGS		=	-Wall -Wextra -Werror -I $(H_DIR) -I $(LIBFT_DIR)

SRCS		=	stack_check.c \
				stack_create.c \
				stack_utils.c \
				
OBJS		=	$(SRCS:.c=.o)

# LIBFT_OBJ	=	$(wildcard $(LIBFT_DIR)*.o)

ALL_FILES	=	$(LIBFT_DIR)*.c $(LIBFT_DIR)*.h $(SRCS)

PROGRAM		=	"PUSH SWAP"
EXEC_NAME	=	"push_swap"

DEFAULT		=	\033[0m
RED			=	\033[1;31m
CYAN		=	\033[1;36m
PINK		=	\033[1;35m
GREEN		=	\033[1;32m
YELLOW		=	\033[1;33m
REWHITE		=	\033[1;7;97m
RECYAN		=	\033[1;7;36m
REPINK		=	\033[1;7;35m
RERED		=	\033[1;7;31m
REGREEN		=	\033[1;7;32m
REYELLOW	=	\033[1;7;33m

TOTAL_FILES = $(words $(OBJS) $(LIBFT_OBJ))
COMPLETED = 0

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

all: $(LIBFT) $(NAME)

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

$(NAME): $(LIBFT) $(OBJS)
		cp $(LIBFT) $(NAME)
		$(AR) $(NAME) $(OBJS)
		@echo "$(PROGRAM) created as $(EXEC_NAME)"

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@
		@$(call update_progress)

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
		$(RM) $(OBJS)

fclean: clean
		$(RM) $(NAME)
		$(RM) norminette.log
		@make fclean -C $(LIBFT_DIR)

re: fclean all

.PHONY: all clean fclean re norm