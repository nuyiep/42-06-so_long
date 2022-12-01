/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:45:14 by plau              #+#    #+#             */
/*   Updated: 2022/12/01 21:36:46 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	check_if_exist(t_prg *prg)
{
	if (prg->map.max_col == 0)
		exit_fail("No collectible in the map");
	if (prg->ply.pos.x == -1 || prg->ply.pos.y == -1)
		exit_fail("No player in the map");
	if (prg->map.exit_pos.x == -1 || prg->map.exit_pos.y == -1)
		exit_fail("No exit in the map");
}

void	check_and_set(t_vec *pos, int x, int y, char c)
{
	if (pos->x != -1 || pos->y != -1)
	{
		if (c == 'P')
			exit_fail("More than one player in the map");
		if (c == 'E')
			exit_fail("More than one exit in the map");
	}
	pos->x = x;
	pos->y = y;
}

/**
 * Get player position (x, y)
 * Count how many collectible (C) in the map
 */
void	get_data(t_prg *prg)
{
	int	k;
	int	j;

	k = -1;
	while (++k < prg->map.size.y)
	{
		j = -1;
		while (prg->map.map[k][++j] != '\0')
		{
			if (prg->map.map[k][j] == 'C')
				prg->map.max_col++;
			if (prg->map.map[k][j] == 'P')
				check_and_set(&prg->ply.pos, k, j, 'P');
			if (prg->map.map[k][j] == 'E')
				check_and_set(&prg->map.exit_pos, k, j, 'E');
		}
	}
	check_if_exist(prg);
}
