/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 16:12:14 by plau              #+#    #+#             */
/*   Updated: 2022/11/30 22:59:19 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

void	fill(char **tab, t_vec size, t_vec cur, char to_fill)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
			|| tab[cur.y][cur.x] != to_fill)
		return ;
	
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_vec){cur.x - 1, cur.y}, to_fill);
	fill(tab, size, (t_vec){cur.x + 1, cur.y}, to_fill);
	fill(tab, size, (t_vec){cur.x, cur.y - 1}, to_fill);
	fill(tab, size, (t_vec){cur.x, cur.y + 1}, to_fill);
}

void	flood_fill(char **tab, t_vec size, t_vec begin)
{
	fill(tab, size, begin, tab[begin.y][begin.x]);
}

/* Check for valid path C, 0 , E becomes F */
void	get_coordinates(t_prg *prg)
{
	int	k;
	int	j;
	t_vec c;
	t_vec zero;
	t_vec e;

	k = 0;
	j = 0;
	while (k < prg->map.size.y)
	{
		j = 0;
		while (prg->map.map[k][j] != '\0')
		{
			ft_printf("K: %d   ", k);
			ft_printf("J: %d\n", j);
			if (prg->map.map[k][j] == 'C')
			{
				c.x = k;
				c.y = j;
			}
			else if (prg->map.map[k][j] == '0')
			{
				zero.x = k;
				zero.y = j;
			}
			else if (prg->map.map[k][j] == 'E')
			{
				e.x = k;
				e.y = j;
			} 
			j++;
		}
		k++;
	}
	ft_printf("HIWORLD\n");
}

void	check_valid_path(t_prg *prg)
{
	int	k;
	
	k = 0;
	t_vec	size = {prg->map.size.x, prg->map.size.y};
	get_coordinates(prg);
	t_vec	begin_c = {begin_c.x, begin_c.y};
	t_vec	begin_0 = {begin_0.x, begin_0.y};
	t_vec	begin_e = {begin_e.x, begin_e.y};
	//t_vec	begin = {prg->ply.pos.x, prg->ply.pos.y};
	// ft_printf("%d\n", prg->ply.pos.x);
	// ft_printf("%d\n", prg->ply.pos.y);
	
	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
	flood_fill(prg->map.map, size, begin_c);
	k = 0;
	ft_printf("\n");
	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
	flood_fill(prg->map.map, size, begin_0);
	k = 0;
	ft_printf("\n");
	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
	flood_fill(prg->map.map, size, begin_e);
	k = 0;
	ft_printf("\n");
	while (k < prg->map.size.y)
		ft_printf("%s\n", prg->map.map[k++]);
}
