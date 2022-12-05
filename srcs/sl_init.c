/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:43:30 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 19:17:49 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Initialize the sprites */
void	init_sprites(t_prg *prg)
{
	prg->map.p_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/player.xpm",
			&prg->map.p_img.size.x, &prg->map.p_img.size.y);
	prg->map.c_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/c.xpm",
			&prg->map.c_img.size.x, &prg->map.c_img.size.y);
	prg->map.d_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/door.xpm",
			&prg->map.d_img.size.x, &prg->map.d_img.size.y);
	prg->map.f_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/floor.xpm",
			&prg->map.f_img.size.x, &prg->map.f_img.size.y);
	prg->map.w_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/wall.xpm",
			&prg->map.w_img.size.x, &prg->map.w_img.size.y);
	prg->map.e_img.img = mlx_xpm_file_to_image(prg->mlx, "sprites/enemy.xpm",
			&prg->map.e_img.size.x, &prg->map.e_img.size.y);
}

/* Initialize player position, collectible and steps */
void	init_player(t_prg *prg)
{
	prg->ply.pos.x = -1;
	prg->ply.pos.y = -1;
	prg->ply.col = 0;
	prg->ply.steps = 0;
}

/* Initialize map's size */
void	init_map(t_prg *prg)
{
	prg->map.size.x = 0;
	prg->map.size.y = 0;
	prg->map.exit_pos.x = -1;
	prg->map.exit_pos.y = -1;
}

/* Initialize enemy position */
void	init_enemy(t_prg *prg)
{
	prg->emy.x = 0;
	prg->emy.y = 0;
}

/* Main function for initialization */
void	init_game(t_prg *prg)
{
	prg->mlx = mlx_init();
	init_player(prg);
	init_sprites(prg);
	init_map(prg);
	init_enemy(prg);
}
