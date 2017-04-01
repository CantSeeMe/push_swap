#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jye <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/12/19 16:32:14 by jye               #+#    #+#              #
#    Updated: 2017/01/03 16:57:56 by jye              ###   ########.fr        #
#                                                                              #
#******************************************************************************#

# Compiler

CC					=	gcc
CFLAG				=	-Wall -Wextra -Werror -g
ULIB_FLAG			=	-L $(OBJ_PATH)/$(UTILS_PATH) -lutils
LIBFT_FLAG			=	-L libft -lft
LIBFT_PRINTF_FLAG	=	-L ft_printf -lftprintf

# Directories

SRC_PATH		=	srcs
UTILS_PATH		=	utils
OBJ_PATH		=	objs
INC_PATH		=	includes
PSWP_PATH		=	push_swap
CHK_PATH		=	checker

# Source files

UTILS_FILES		=	parse.c	    \
					stack.c		\
					f_atoi.c	\
					stackbis.c
PSWP_FILES		=	push_swap.c		\
					merge_unlock.c	\
					sizeof_stack.c	\
					chk_order_var.c	\
					merge_lock.c	\
					set_head.c		\
					get_opt_ins.c	\
					merge3.c		\
					merge2.c		\
					merge.c			
CHK_FILES		=	checker.c	\
					debug.c		\
					get_sline.c	\
					inst.c		\
					inst2.c		\
					inst3.c		\
					parser.c	\
					get_inst.c	\
					chk_swap.c	

# Object files

UTILS_OBJ		=	$(addprefix $(OBJ_PATH)/,	\
					$(addprefix $(UTILS_PATH)/, \
					$(addsuffix .o,				\
					$(basename $(UTILS_FILES)))))
PSWP_OBJ		=	$(addprefix $(OBJ_PATH)/,	\
					$(addprefix $(PSWP_PATH)/,	\
					$(addsuffix .o,				\
					$(basename $(PSWP_FILES)))))
CHK_OBJ			=	$(addprefix $(OBJ_PATH)/,	\
					$(addprefix $(CHK_PATH)/,	\
					$(addsuffix .o,				\
					$(basename $(CHK_FILES)))))
# Binary name

PSWP_NAME		=	push_swap
CHK_NAME		=	checker
UTILS_LIB		=	libutils.a

# Rules

all			: pretty $(PSWP_NAME) $(CHK_NAME)
	@printf "\r\033[2K\033[0mOK\n"

.PHONY		: clean fclean re

clean		:
	@printf "Never gonna give you up \xe2\x99\xab~~\n"
	@make -C libft fclean
	@make -C ft_printf fclean
	@/bin/rm -rf $(OBJ_PATH)

fclean		: clean
	@/bin/rm -rf $(PSWP_NAME)
	@/bin/rm -rf $(CHK_NAME)
	@/bin/rm -rf $(PSWP_NAME).dSYM
	@/bin/rm -rf $(CHK_NAME).dSYM

re			: fclean all

$(PSWP_NAME): $(PSWP_OBJ) lib $(OBJ_PATH)/$(UTILS_PATH)/$(UTILS_LIB)
	@$(CC) $(PSWP_OBJ) $(ULIB_FLAG) $(LIBFT_PRINTF_FLAG) $(LIBFT_FLAG) -o $@
	@printf "Compiling %s\r" $@
	@printf "\033[2K"

$(CHK_NAME)	: $(CHK_OBJ) lib $(OBJ_PATH)/$(UTILS_PATH)/$(UTILS_LIB)
	@$(CC) $(CHK_OBJ) $(ULIB_FLAG) $(LIBFT_PRINTF_FLAG) $(LIBFT_FLAG) -o $@
	@printf "\033[2K"
	@printf "Compiling %s\r" $@

$(OBJ_PATH)/$(UTILS_PATH)/$(UTILS_LIB) : $(UTILS_OBJ)
	@ar -rcs $@ $(UTILS_OBJ)
	@printf "\033[2K"
	@printf "Compiling %s\r" $@

lib			:
	@make -C libft
	@make -C ft_printf

$(OBJ_PATH)/$(UTILS_PATH)/%.o	: $(SRC_PATH)/$(UTILS_PATH)/%.c
	@/bin/mkdir -p $(OBJ_PATH)
	@/bin/mkdir -p $(OBJ_PATH)/$(UTILS_PATH)
	@$(CC) $(CFLAG) -c -o $@ $< -I$(INC_PATH)
	@printf "\033[2K"
	@printf "\033[31m\033[1mGenerating %s file\r" $@

$(OBJ_PATH)/$(PSWP_PATH)/%.o	: $(SRC_PATH)/$(PSWP_PATH)/%.c
	@/bin/mkdir -p $(OBJ_PATH)
	@/bin/mkdir -p $(OBJ_PATH)/$(PSWP_PATH)
	@$(CC) $(CFLAG) -c -o $@ $< -I$(INC_PATH)
	@printf "\033[2K"
	@printf "\033[32m\033[1mGenerating %s file\r" $@

$(OBJ_PATH)/$(CHK_PATH)/%.o		: $(SRC_PATH)/$(CHK_PATH)/%.c
	@/bin/mkdir -p $(OBJ_PATH)
	@/bin/mkdir -p $(OBJ_PATH)/$(CHK_PATH)
	@$(CC) $(CFLAG) -c -o $@ $< -I$(INC_PATH)
	@printf "\033[2K"
	@printf "\033[33m\033[1mGenerating %s file\r" $@

pretty							:
	@printf "\033[34m\033[1m"
	@/bin/echo "      ___         ___           ___           ___                    ___           ___           ___           ___   "
	@/bin/echo "     /\  \       /\  \         /\__\         /\  \                  /\__\         /\  \         /\  \         /\  \  "
	@/bin/echo "    /::\  \      \:\  \       /:/ _/_        \:\  \                /:/ _/_       _\:\  \       /::\  \       /::\  \ "
	@/bin/echo "   /:/\:\__\      \:\  \     /:/ /\  \        \:\  \              /:/ /\  \     /\ \:\  \     /:/\:\  \     /:/\:\__\ "
	@/bin/echo "  /:/ /:/  /  ___  \:\  \   /:/ /::\  \   ___ /::\  \            /:/ /::\  \   _\:\ \:\  \   /:/ /::\  \   /:/ /:/  /"
	@/bin/echo " /:/_/:/  /  /\  \  \:\__\ /:/_/:/\:\__\ /\  /:/\:\__\          /:/_/:/\:\__\ /\ \:\ \:\__\ /:/_/:/\:\__\ /:/_/:/  / "
	@/bin/echo " \:\/:/  /   \:\  \ /:/  / \:\/:/ /:/  / \:\/:/  \/__/          \:\/:/ /:/  / \:\ \:\/:/  / \:\/:/  \/__/ \:\/:/  /  "
	@/bin/echo "  \::/__/     \:\  /:/  /   \::/ /:/  /   \::/__/                \::/ /:/  /   \:\ \::/  /   \::/__/       \::/__/   "
	@/bin/echo "   \:\  \      \:\/:/  /     \/_/:/  /     \:\  \                 \/_/:/  /     \:\/:/  /     \:\  \        \:\  \   "
	@/bin/echo "    \:\__\      \::/  /        /:/  /       \:\__\                  /:/  /       \::/  /       \:\__\        \:\__\  "
	@/bin/echo "     \/__/       \/__/         \/__/         \/__/                  \/__/         \/__/         \/__/         \/__/ "
	@printf "\033[0m\n"
