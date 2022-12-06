/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_hook_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:43:19 by plau              #+#    #+#             */
/*   Updated: 2022/12/06 18:58:26 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Putting image to window */
/* mlx_loop will keep looping even if user is not inputting any data */
int	user_update(t_prg *prg)
{
	prg->win.fps++;
	mlx_clear_window(prg->mlx, prg->win.win);
	sl_display_image(prg);
	if (prg->win.fps > FPS)
		prg->win.fps = 0;
	check_state(prg);
	return (0);
}

/* For exiting by clicking the cross on the window's frame */
int	sl_windowexit(void)
{
	ft_printf("Thanks for playing\n");
	exit(0);
	return (0);
}

/* Main function for printing images */
/* mlx_hook - hook user input  */
void	loop_game(t_prg *prg)
{
	mlx_hook(prg->win.win, EXIT_PRESS, EXIT_MASK, &sl_windowexit,
		prg);
	mlx_hook(prg->win.win, MLX_PRESS, MLX_MASK, &user_input, prg);
	mlx_loop_hook(prg->mlx, &user_update, prg);
	mlx_loop(prg->mlx);
}
