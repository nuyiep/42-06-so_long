/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:06:45 by plau              #+#    #+#             */
/*   Updated: 2022/11/29 18:28:05 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SL_H
# define SL_H

# include "../libft/srcs/libft.h"
# include "../libft/srcs/get_next_line.h"
# include "../libft/srcs/ft_printf.h"
# include <mlx.h>

# define KEY_ESC		53
# define KEY_UP			126
# define KEY_DOWN		125
# define KEY_LEFT		123
# define KEY_RIGHT		124

# define MLX_PRESS 		2	
# define MLX_MASK 		0

# define PLY_MVSPEED	64

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
	t_img	wall;
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
}	t_prg;

/* Initialize */
void	init_game(t_prg *prg);
void	init_sprites(t_prg *prg);
void	init_mlx(t_prg *prg);

/* Hooks */
void	loop_game(t_prg *prg);

/* Exit functions */
int		exit_success(void);
int		exit_fail(char *error);

#endif