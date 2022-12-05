/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:06:45 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 22:31:25 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# include "../libft/srcs/libft.h"
# include "../libft/srcs/get_next_line.h"
# include "../libft/srcs/ft_printf.h"
# include <mlx.h>

/* Mac key codes */
# define KEY_ESC		53
# define KEY_W			13
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

/* MLX hook- hooking event and mask */
/* 2 is key press */
/* No event mask here so 0 */
# define MLX_PRESS 		2	
# define MLX_MASK 		0

/* Player movement */
# define PLY_MVSPEED	64

# define PINK			0xffb6c1
# define WHITE			0xffffff

typedef struct s_vec
{
	int	x;
	int	y;
}	t_vec;

typedef struct s_win
{
	void	*win;
	t_vec	size;
	int		fps;
}	t_win;

typedef struct s_img
{
	void	*img;
	t_vec	size;
}	t_img;

typedef struct s_map
{
	t_img	c_img;
	t_img	d_img;
	t_img	e_img;
	t_img	f_img;
	t_img	p_img;
	t_img	w_img;
	t_vec	size;
	t_vec	exit_pos;
	char	**map;
	int		max_col;
}	t_map;

typedef struct s_ply
{
	int		steps;
	int		col;
	t_vec	pos;
}	t_ply;

typedef struct s_prg
{
	void	*mlx;
	t_win	win;
	t_map	map;
	t_ply	ply;
	t_vec	emy;
}	t_prg;

/* Initialize */
void	init_game(t_prg *prg);
void	init_sprites(t_prg *prg);
void	init_mlx(t_prg *prg);

/* Hooks */
void	loop_game(t_prg *prg);
int		user_input(int keycode, t_prg *prg);

/* Map */
void	check_map(t_prg *prg, int ac, char **av);
void	check_valid_path(t_prg *prg);
void	get_data(t_prg *prg);
void	check_each_line(t_prg *prg, char *path);

/* Display map and on screen steps */
void	sl_display_image(t_prg *prg);
int		sl_check_enemy(t_prg *prg);
void	sl_on_screen_steps(t_prg *prg);

/* Handle collectibles */
void	check_state(t_prg *prg);

/* Exit functions */
int		exit_success(void);
int		exit_fail(char *error);

/* Helper function */
void	for_printing(t_prg *prg);
void	sl_printmap(t_prg *prg, char **map);

#endif