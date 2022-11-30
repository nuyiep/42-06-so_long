/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:12:14 by plau              #+#    #+#             */
/*   Updated: 2022/11/30 23:20:06 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check for valid path C, 0 , E becomes F */
void	fill(char **tab, t_vec size, t_vec cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
			|| (tab[cur.y][cur.x] != '0' && tab[cur.y][cur.x] != 'P' && 
				tab[cur.y][cur.x] != 'C' && tab[cur.y][cur.x] != 'E'))
		return ;
	
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_vec){cur.x - 1, cur.y});
	fill(tab, size, (t_vec){cur.x + 1, cur.y});
	fill(tab, size, (t_vec){cur.x, cur.y - 1});
	fill(tab, size, (t_vec){cur.x, cur.y + 1});
}

void	flood_fill(char **tab, t_vec size, t_vec begin)
{
	fill(tab, size, begin);
}

void	check_valid_path(t_prg *prg)
{
	int	k;
	
	k = 0;
	t_vec	size = {prg->map.size.x, prg->map.size.y};
	t_vec	begin_c = {begin_c.x, begin_c.y};
	//t_vec	begin = {prg->ply.pos.x, prg->ply.pos.y};

	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
	flood_fill(prg->map.map, size, begin_c);
	k = 0;
	ft_printf("\n");
	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
}
