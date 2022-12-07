/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:42:53 by plau              #+#    #+#             */
/*   Updated: 2022/12/07 15:37:55 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check whether collided into wall, if no collision return 0 */
int	col(t_prg *prg, int x, int y)
{
	if (prg->map.map[y][x] == '1')
		return (1);
	return (0);
}

/* Apply user input for player */
int	user_input_player(int keycode, t_prg *prg)
{
	if (keycode == KEY_ESC)
		exit_success();
	else if (keycode == KEY_W && !col(prg, prg->ply.pos.x, prg->ply.pos.y - 1))
		prg->ply.pos.y--;
	else if (keycode == KEY_S && !col(prg, prg->ply.pos.x, prg->ply.pos.y + 1))
		prg->ply.pos.y++;
	else if (keycode == KEY_A && !col(prg, prg->ply.pos.x - 1, prg->ply.pos.y))
		prg->ply.pos.x--;
	else if (keycode == KEY_D && !col(prg, prg->ply.pos.x + 1, prg->ply.pos.y))
		prg->ply.pos.x++;
	else
		return (0);
	prg->ply.steps++;
	ft_printf("Movement count: %d\n", prg->ply.steps);
	return (0);
}

/* Apply user input for enemy */
void	user_input_enemy(int keycode, t_prg *prg)
{
	if (keycode == KEY_UP && !col(prg, prg->emy.x, prg->emy.y - 1))
		prg->emy.y--;
	else if (keycode == KEY_DOWN && !col(prg, prg->emy.x, prg->emy.y + 1))
		prg->emy.y++;
	else if (keycode == KEY_LEFT && !col(prg, prg->emy.x - 1, prg->emy.y))
		prg->emy.x--;
	else if (keycode == KEY_RIGHT && !col(prg, prg->emy.x + 1, prg->emy.y))
		prg->emy.x++;
}

/* Main function for user_input */
int	user_input(int keycode, t_prg *prg)
{
	if (sl_check_enemy(prg))
	{
		user_input_player(keycode, prg);
		user_input_enemy(keycode, prg);
		if (prg->ply.pos.y == prg->emy.y && prg->ply.pos.x == prg->emy.x)
		{
			ft_printf("Game Over\n");
			exit(0);
		}
	}
	else
		user_input_player(keycode, prg);
	return (0);
}
