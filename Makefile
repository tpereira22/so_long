# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: timartin <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/02 15:46:43 by timartin          #+#    #+#              #
#    Updated: 2022/11/02 15:46:47 by timartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= so_long

SRCS		= srcs/so_long.c srcs/maps.c srcs/window.c srcs/check_map.c srcs/draw.c srcs/hooks.c

OBJS		= $(SRCS:.c=.o)

LIBFTA		= ./libft/libft.a

MLX		= ./mlx/libmlx.a

RM		= rm -f

CC		= gcc -Wall -Wextra -Werror

MLX_FLAGS	= -lXext -lX11 -lm -lz

.c.o:
			@$(CC) -c $< -o $@

all:		$(NAME)

$(NAME): 	 $(MLX) $(LIBFTA) $(OBJS)
			$(CC) $(OBJS) $(MLX) $(LIBFTA) $(MLX_FLAGS) -o $(NAME)
			
$(MLX):
			@make -C mlx

$(LIBFTA):
			@make -C libft

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)
			make -C libft fclean
			make -C mlx clean

re:			fclean all

.PHONY:		all clean re fclean