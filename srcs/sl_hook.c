/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:43:19 by plau              #+#    #+#             */
/*   Updated: 2022/11/30 22:41:58 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Apply user input */
int	user_input(int keycode, t_prg *prg)
{
	if (keycode == KEY_ESC)
		exit_success();
	else if (keycode == KEY_W)
		prg->ply.pos.y -= PLY_MVSPEED;
	else if (keycode == KEY_S)
		prg->ply.pos.y += PLY_MVSPEED;
	else if (keycode == KEY_A)
		prg->ply.pos.x -= PLY_MVSPEED;
	else if (keycode == KEY_D)
		prg->ply.pos.x += PLY_MVSPEED;
	return (0);
}

/* Putting image to window */
int	user_update(t_prg *prg)
{
	mlx_clear_window(prg->mlx, prg->win.win);
	mlx_put_image_to_window(prg->mlx, prg->win.win,
		prg->map.p_img.img, prg->ply.pos.x, prg->ply.pos.y);
	return (0);
}

/* Main function for printing images */
void	loop_game(t_prg *prg)
{
	mlx_hook(prg->win.win, MLX_PRESS, MLX_MASK, &user_input, prg);
	mlx_loop_hook(prg->mlx, &user_update, prg);
	mlx_loop(prg->mlx);
}
