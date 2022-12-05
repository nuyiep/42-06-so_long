/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:12:14 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 12:05:33 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check for valid path 0, P , C and E becomes F */
void	flood_fill(char **tab, t_vec size, t_vec cur)
{
	if (cur.y >= 0 && cur.y < size.y && cur.x >= 0 && cur.x < size.x
		&& (tab[cur.y][cur.x] == '0' || tab[cur.y][cur.x] == 'P'
		|| tab[cur.y][cur.x] == 'C' || tab[cur.y][cur.x] == 'E'))
	{
		tab[cur.y][cur.x] = 'F';
		flood_fill(tab, size, (t_vec){cur.x - 1, cur.y});
		flood_fill(tab, size, (t_vec){cur.x + 1, cur.y});
		flood_fill(tab, size, (t_vec){cur.x, cur.y - 1});
		flood_fill(tab, size, (t_vec){cur.x, cur.y + 1});
	}
}

/* Check whether there is a valid path to win the game */
void	check_valid_path(t_prg *prg)
{
	int		k;
	int		j;
	char	**temp_map;

	temp_map = malloc(sizeof(char *) * prg->map.size.y);
	k = -1;
	while (++k < prg->map.size.y)
		temp_map[k] = ft_strdup(prg->map.map[k]);
	sl_printmap(prg, temp_map);
	flood_fill(temp_map, prg->map.size, prg->ply.pos);
	sl_printmap(prg, temp_map);
	j = -1;
	while (++j < prg->map.size.y)
	{
		k = -1;
		while (++k < prg->map.size.x)
			if (ft_strchr("CEP", temp_map[j][k]))
				exit_fail("No valid path");
	}
	temp_map[prg->map.size.y] = 0;
	j = -1;
	while (++j < prg->map.size.y)
		free(temp_map[j]);
	free(temp_map);
}

/* For printing */
	// while (k < prg->map.size.y)
	// 	ft_printf("%s\n", prg->map.map[k++]);

/* 
- if (temp_map[j][k] == 'C' || temp_map[j][k] == 'P' || temp_map[j][k] == 'E')
- can be written as ft_strchr("CEP", temp_map[j][k] :D

*/