/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:43:19 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 11:50:14 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Putting image to window */
int	user_update(t_prg *prg)
{
	mlx_clear_window(prg->mlx, prg->win.win);
	sl_display_image(prg);
	return (0);
}

/* Main function for printing images */
/* mlx_hook - hook user input  */
void	loop_game(t_prg *prg)
{
	mlx_hook(prg->win.win, MLX_PRESS, MLX_MASK, &user_input, prg);
	mlx_loop_hook(prg->mlx, &user_update, prg);
	mlx_loop(prg->mlx);
}
