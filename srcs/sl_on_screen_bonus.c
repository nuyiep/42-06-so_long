/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_on_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:07:18 by plau              #+#    #+#             */
/*   Updated: 2022/12/06 17:14:42 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Print the number of steps on screen */
void	sl_on_screen_steps(t_prg *prg)
{
	char	*steps;
	char	*str;

	steps = ft_itoa(prg->ply.steps);
	str = ft_strjoin("Movement count: ", steps);
	mlx_string_put(prg->mlx, prg->win.win, 10, 15, WHITE, str);
	free(steps);
	free(str);
}

/* Initialize window after error checking */
void	init_window(t_prg *prg)
{
	prg->win.win = mlx_new_window(prg->mlx, prg->map.size.x * PLY_MVSPEED,
			prg->map.size.y * PLY_MVSPEED, "so_long");
	prg->win.fps = 0;
	prg->win.size.x = prg->map.size.x;
	prg->win.size.y = prg->map.size.y;
}

/* Add animation for player */
void	sl_player_ani(t_prg *prg)
{
	if (prg->win.fps < FPS / 2)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.p_img.img,
			prg->ply.pos.x * PLY_MVSPEED, prg->ply.pos.y * PLY_MVSPEED - 1);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.p_img.img,
			prg->ply.pos.x * PLY_MVSPEED, prg->ply.pos.y * PLY_MVSPEED + 1);
}

/* Add animation for enemy */
void	sl_enemy_ani(t_prg *prg)
{
	if (prg->win.fps < FPS / 2)
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.e_img.img,
			prg->emy.x * PLY_MVSPEED, prg->emy.y * PLY_MVSPEED - 1);
	else
		mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.e_img.img,
			prg->emy.x * PLY_MVSPEED, prg->emy.y * PLY_MVSPEED + 1);
}
