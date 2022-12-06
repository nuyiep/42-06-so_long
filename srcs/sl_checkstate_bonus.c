/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_checkstate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 12:55:10 by plau              #+#    #+#             */
/*   Updated: 2022/12/06 13:17:53 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/**
 * Check if the player has collected all the collectibles
 * If ply pos == C
 * 		-> Change to floor
 * 		-> Ply's C++
 * If ply pos == E
 * 		-> If not collected all -> Do nothing
 * 		-> If collected all -> exit success
 */
void	check_state(t_prg *prg)
{
	if (prg->map.map[prg->ply.pos.y][prg->ply.pos.x] == 'C')
	{
		prg->map.map[prg->ply.pos.y][prg->ply.pos.x] = 'F';
		prg->ply.col++;
	}
	if (prg->map.map[prg->ply.pos.y][prg->ply.pos.x] == 'E')
	{
		if (prg->ply.col == prg->map.max_col)
		{
			ft_printf("You won!\n");
			exit_success();
		}
	}
}
