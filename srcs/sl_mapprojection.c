/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_mapprojection.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 14:40:29 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 21:52:06 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Display the entire map and its sprites onto the window- (constant) */
void	sl_map_projection(t_prg *prg)
{
	int	k;
	int	j;

	j = 0;
	while (j < prg->map.size.y)
	{
		k = 0;
		while (k < prg->map.size.x)
		{
			mlx_put_image_to_window(prg->mlx, prg->win.win, prg->map.f_img.img,
				(k * PLY_MVSPEED), (j * PLY_MVSPEED));
			if (prg->map.map[j][k] == '1')
				mlx_put_image_to_window(prg->mlx, prg->win.win,
					prg->map.w_img.img, (k * PLY_MVSPEED), (j * PLY_MVSPEED));
			if (prg->map.map[j][k] == 'E')
				mlx_put_image_to_window(prg->mlx, prg->win.win,
					prg->map.d_img.img, (k * PLY_MVSPEED), (j * PLY_MVSPEED));
			if (prg->map.map[j][k] == 'C')
				mlx_put_image_to_window(prg->mlx, prg->win.win,
					prg->map.c_img.img, (k * PLY_MVSPEED), (j * PLY_MVSPEED));
			k++;
		}
		j++;
	}
}

/* Print player */
void	sl_print_player(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->win.win,
		prg->map.p_img.img, prg->ply.pos.x * PLY_MVSPEED,
		prg->ply.pos.y * PLY_MVSPEED);
}

/* Print enemy */
void	sl_print_enemy(t_prg *prg)
{
	mlx_put_image_to_window(prg->mlx, prg->win.win,
		prg->map.e_img.img, prg->emy.x * PLY_MVSPEED,
		prg->emy.y * PLY_MVSPEED);
}

/* If there is enemy, return 1*/
int	sl_check_enemy(t_prg *prg)
{
	int	k;
	int	j;

	j = 0;
	while (j < prg->map.size.y)
	{
		k = 0;
		while (k < prg->map.size.x)
		{
			if (prg->map.map[j][k] == 'N')
				return (1);
			k++;
		}
		j++;
	}
	return (0);
}

/* Main function for map projection */
void	sl_display_image(t_prg *prg)
{
	sl_map_projection(prg);
	sl_print_player(prg);
	if (sl_check_enemy(prg))
		sl_print_enemy(prg);
	sl_on_screen_steps(prg);
}
