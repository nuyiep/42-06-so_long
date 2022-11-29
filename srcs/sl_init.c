/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:43:30 by plau              #+#    #+#             */
/*   Updated: 2022/11/29 21:12:35 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	init_mlx(t_prg *prg)
{
	prg->mlx = mlx_init();
	prg->win.win = mlx_new_window(prg->mlx, 1280, 800, "so_long");
}

void	init_sprites(t_prg *prg)
{
	prg->map.p_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/player.xpm",
			&prg->map.p_img.size.x, &prg->map.p_img.size.y);	
	prg->map.c_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/c.xpm",
			&prg->map.c_img.size.x, &prg->map.c_img.size.y);
	prg->map.d_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/door.xpm",
			&prg->map.d_img.size.x, &prg->map.d_img.size.y);
	prg->map.e_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/enemy.xpm",
			&prg->map.e_img.size.x, &prg->map.e_img.size.y);
	prg->map.f_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/floor.xpm",
			&prg->map.f_img.size.x, &prg->map.f_img.size.y);
	prg->map.wall.img = mlx_xpm_file_to_image(prg->mlx, "sprites/wall.xpm",
			&prg->map.wall.size.x, &prg->map.wall.size.y);
}

void	init_player(t_prg *prg)
{
	prg->ply.pos.x = 0;
	prg->ply.pos.y = 0;
	prg->ply.col = 0;
	prg->ply.steps = 0;
}

void	init_game(t_prg *prg)
{
	init_mlx(prg);
	init_player(prg);
	init_sprites(prg);
}
