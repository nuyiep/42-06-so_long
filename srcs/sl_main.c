/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:26:08 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 15:36:46 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Start of the main function */
int	main(int ac, char **av)
{	
	t_prg	prg;

	init_game(&prg);
	check_map(&prg, ac, av);
	prg.win.win = mlx_new_window(prg.mlx, prg.map.size.x * PLY_MVSPEED,
			prg.map.size.y * PLY_MVSPEED, "so_long");
	loop_game(&prg);
	return (exit_success());
}

/**
 * Init
 * Map parsing
 * Set image
 * print character
 */