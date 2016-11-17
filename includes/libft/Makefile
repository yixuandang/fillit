# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ydang <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/10/29 02:26:13 by ydang             #+#    #+#              #
#    Updated: 2016/10/30 00:16:56 by ydang            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

NOC=\033[0m
OKC=\033[94;1m
ERC=\033[31m
WAC=\033[33m
GRE=\x1b[32;01m

CC = gcc
CFLAGS += -Wall -Werror -Wextra

SRC_PATH = ./srcs/

SRC_NAME += ft_bzero.c \
			ft_memccpy.c \
			ft_memcpy.c \
			ft_memmove.c \
			ft_memchr.c \
			ft_memcmp.c \
			ft_strdup.c \
			ft_memset.c \
			ft_putchar.c \
			ft_putstr.c \
			ft_strcat.c \
			ft_strncat.c \
			ft_strlcat.c \
			ft_strchr.c \
			ft_strrchr.c \
			ft_strstr.c \
			ft_strnstr.c \
			ft_strcmp.c \
			ft_strncmp.c \
			ft_strcpy.c \
			ft_strlen.c \
			ft_strncpy.c \
			ft_atoi.c \
			ft_itoa.c \
			ft_isalpha.c \
			ft_isdigit.c \
			ft_isalnum.c \
			ft_isascii.c \
			ft_isprint.c \
			ft_toupper.c \
			ft_tolower.c \
			ft_memalloc.c \
			ft_memdel.c \
			ft_strnew.c \
			ft_strdel.c \
			ft_strclr.c \
			ft_striter.c \
			ft_strmap.c \
			ft_strmapi.c \
			ft_strequ.c \
			ft_strnequ.c \
			ft_strsub.c \
			ft_strjoin.c \
			ft_strtrim.c \
			ft_strsplit.c \
			ft_putendl.c \
			ft_putnbr.c \
			ft_putstr_fd.c \
			ft_putchar_fd.c \
			ft_putendl_fd.c \
			ft_putnbr_fd.c \
			ft_lstnew.c \
			ft_lstdelone.c \
			ft_lstdel.c \
			ft_lstadd.c \
			ft_lstiter.c \
			ft_lstmap.c \
			ft_strndup.c

SRC = $(addprefix $(SRC_PATH), $(SRC_NAME))

OBJ_PATH = ./obj/
OBJ_NAME = $(SRC_NAME:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_NAME))

INC_PATH = ./includes/
INC = $(addprefix -I, $(INC_PATH))

all: $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)/%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CFLAGS) $(INC) -o $@ -c $<
	@echo -n =

$(NAME): $(OBJ)
	@echo "$(OKC)\nLIBFT:\t\tCREATING THE LIBRARY / \c"
	@ar -rc $(NAME) $?
	@echo "$(OKC)GENERATING THE INDEX$(NOC)"
	@ranlib $(NAME)
	@echo "$(OKC)LIBFT:\t\tLIBFT READY$(NOC)"
	@echo "$(GRE)=============$(WAC)===============$(ERC)===============$(OKC)===============$(NOC)"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "$(WAC)LIBFT:\t\tREMOVING OBJ PATH: ./includes/libft/obj/$(NOC)"

fclean: clean
	@rm -rf $(NAME)
	@echo "$(OKC)LIBFT:\t\tLIBFT.A REMOVED$(NOC)"
	@echo "$(GRE)=============$(WAC)===============$(ERC)===============$(OKC)===============$(NOC)"

re: fclean all

.PHONY: all, clean, fclean, re
