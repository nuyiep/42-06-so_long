/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_floodfill.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:12:14 by plau              #+#    #+#             */
/*   Updated: 2022/11/30 23:26:16 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check for valid path C, 0 , E becomes F */
void	flood_fill(char **tab, t_vec size, t_vec cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
			|| (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'P' && 
				tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	
	tab[cur.y][cur.x] = 'F';
	flood_fill(tab, size, (t_vec){cur.x - 1, cur.y});
	flood_fill(tab, size, (t_vec){cur.x + 1, cur.y});
	flood_fill(tab, size, (t_vec){cur.x, cur.y - 1});
	flood_fill(tab, size, (t_vec){cur.x, cur.y + 1});
}

void	check_valid_path(t_prg *prg)
{
	int	k;
	
	k = 0;
	t_vec	size = {prg->map.size.x, prg->map.size.y};
	t_vec	begin_c = {1, 1};
	// ft_printf("Begin c.x: %d\n", begin_c.x);
	// ft_printf("Begin c.y: %d\n", begin_c.y);
	// ft_printf("Ply.pos.x: %d\n", prg->ply.pos.x);
	// ft_printf("Ply.pos.y: %d\n", prg->ply.pos.y);
	// t_vec	begin = {prg->ply.pos.x, prg->ply.pos.y};

	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
	flood_fill(prg->map.map, size, begin_c);
	k = 0;
	ft_printf("\n");
	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
}
