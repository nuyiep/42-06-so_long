/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:12:14 by plau              #+#    #+#             */
/*   Updated: 2022/12/01 20:41:37 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check for valid path 0, P , C and E becomes F */
void	flood_fill(char **tab, t_vec size, t_vec cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'P'
		&& tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	tab[cur.y][cur.x] = 'F';
	flood_fill(tab, size, (t_vec){cur.x - 1, cur.y});
	flood_fill(tab, size, (t_vec){cur.x + 1, cur.y});
	flood_fill(tab, size, (t_vec){cur.x, cur.y - 1});
	flood_fill(tab, size, (t_vec){cur.x, cur.y + 1});
}

// Remember to set player position first before floodfill
void	check_valid_path(t_prg *prg)
{
	t_vec	size;
	t_vec	begin_c;

	size = (t_vec){prg->map.size.x, prg->map.size.y};
	begin_c = (t_vec){prg->ply.pos.x, prg->ply.pos.y};
	flood_fill(prg->map.map, size, begin_c);
}
