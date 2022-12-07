# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: plau <plau@student.42.kl>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/29 09:10:03 by plau              #+#    #+#              #
#    Updated: 2022/12/07 15:33:51 by plau             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME        	=   	so_long
LIBFT        	=    	libft/libft.a
MLX            	=    	mlx/libmlx.a
CC            	=    	gcc
RM            	=    	rm -f
CFLAGS       	=    	-Wall -Wextra -Werror -Imlx
MLXFLAGS   		=    	-L /usr/local/lib -lmlx -framework OpenGL -framework AppKit
SRCS_FILES    	=   	sl_main_bonus \
						sl_exit_bonus \
						sl_hook_bonus \
						sl_init_bonus \
						sl_movement_bonus \
						sl_map_bonus \
						sl_floodfill_bonus \
						sl_getdata_bonus \
						sl_helper_bonus \
						sl_mapprojection_bonus \
						sl_checkstate_bonus \
						sl_on_screen_bonus
SRCS       		=     	$(addprefix $(SRCS_DIR), $(addsuffix .c, $(SRCS_FILES)))
OBJS        	=     	$(addprefix $(OBJS_DIR), $(addsuffix .o, $(SRCS_FILES)))
SRCS_DIR    	=    	srcs/
LIBFT_DIR    	=    	libft/
OBJS_DIR    	=    	objs/

all:            
						mkdir -p $(OBJS_DIR)
						make libft
						make $(NAME)

bonus:
						mkdir -p $(OBJS_DIR)
						make $(NAME)

$(OBJS_DIR)%.o: $(SRCS_DIR)%.c
				$(CC) $(CFLAGS) -c $< -o $@

$(NAME):        $(OBJS)
				$(CC) $(CFLAGS) $(LIBFT) $(MLX) $(OBJS) $(MLXFLAGS) -o $(NAME)

libft:
				make -C $(LIBFT_DIR)

clean:
				rm -rf $(OBJS_DIR)
				make clean -C $(LIBFT_DIR)

fclean:            clean
				make fclean -C $(LIBFT_DIR)
				rm -rf $(NAME)

re:                fclean all

.PHONY:            all bonus libft clean fclean re