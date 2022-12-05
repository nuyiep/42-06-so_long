/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_movement.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 15:42:53 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 12:05:51 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Apply user input */
int	user_input(int keycode, t_prg *prg)
{
	if (keycode == KEY_ESC)
		exit_success();
	else if (keycode == KEY_W)
		prg->ply.pos.y--;
	else if (keycode == KEY_S)
		prg->ply.pos.y++;
	else if (keycode == KEY_A)
		prg->ply.pos.x--;
	else if (keycode == KEY_D)
		prg->ply.pos.x++;
	else
		return (0);
	prg->ply.steps++;
	for_printing(prg);
	return (0);
}
