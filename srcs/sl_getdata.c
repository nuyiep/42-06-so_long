/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_getdata.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 14:45:14 by plau              #+#    #+#             */
/*   Updated: 2022/12/01 15:08:53 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/**
 * Player pos: X, Y
 * How many collectible in the map
 */
void	get_data(t_prg *prg)
{
	int	k;
	int	j;

	k = 0;
	while (k < prg->map.size.y)
	{
		j = 0;
		while (prg->map.map[k][j] != '\0')
		{
			if (prg->map.map[k][j] == 'C')
				prg->ply.col++;
			if (prg->map.map[k][j] == 'P')
			{
				prg->ply.pos.x = k;
				prg->ply.pos.y = j;
			}
			j++;
		}
		k++;
	}
}
