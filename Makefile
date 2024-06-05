# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fjenisch <fjenisch@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/05 17:40:23 by fjenisch          #+#    #+#              #
#    Updated: 2024/06/05 19:24:07 by fjenisch         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := fdf

CC = gcc
CFLAGS = -Wall -Wextra -Werror

LIBMLX = ./lib/MLX42
HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm

GETNEXTLINEDIR = ./lib/get_next_line
GETNEXTLINESRC = $(GETNEXTLINEDIR)/get_next_line.c \
$(GETNEXTLINEDIR)/get_next_line_utils.c
GETNEXTLINEOBJ = $(GETNEXTLINESRC:.c=.o)

LIBFTDIR := ./lib/libft
LIBFT := $(LIBFTDIR)/libft.a

SOURCEDIR := ./src
SOURCES := $(SOURCEDIR)/main.C
SOURCESOBJ = $(SOURCES:.c=.o)

# FdF have to come here

all: libft libmlx $(NAME)

libft:
	make -C $(LIBFTDIR)

libmlx:
	cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): libft $(GETNEXTLINEOBJ)
	$(CC) $(GETNEXTLINEOBJ) $(SOURCESOBJ) $(LIBS) $(HEADERS) -o $@ $(LIBFT)

clean:
	make -C $(LIBFTDIR) clean
	rm -rf $(GETNEXTLINEOBJ)¬
	rm -rf $(LIBMLX)/build
	rm -f $(NAME)

fclean: clean
	make -C ./lib/libft fclean
	rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx


