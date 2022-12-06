/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_on_screen_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:07:18 by plau              #+#    #+#             */
/*   Updated: 2022/12/06 18:44:40 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Initialize window after error checking */
void	init_window(t_prg *prg)
{
	prg->win.win = mlx_new_window(prg->mlx, prg->map.size.x * PLY_MVSPEED,
			prg->map.size.y * PLY_MVSPEED, "so_long");
	prg->win.fps = 0;
}

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
