/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_helper.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:30:38 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 15:31:38 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	for_printing(t_prg *prg)
{
	ft_printf("Movement count: %d\n", prg->ply.steps);
}

/*
	//ft_printf("Player collected: %d / %d\n", prg->ply.col, prg->map.max_col);
	// ft_printf("Player current position: (%d, %d)\n", prg->ply.pos.x,
	// 	prg->ply.pos.y);
	// ft_printf("Map size: %d, %d\n", prg->map.size.x, prg->map.size.y);
	// ft_printf("=======================================\n\n");
*/

/* Printing map in shell */
void	sl_printmap(t_prg *prg, char **map)
{
	int	j;

	j = -1;
	while (++j < prg->map.size.y)
		ft_printf("%s\n", map[j]);
	ft_printf("\n");
}
