/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_on_screen.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 21:07:18 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 22:31:01 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Print the number of steps on screen */
void	sl_on_screen_steps(t_prg *prg)
{
	char	*steps;
	char	*str;

	steps = ft_itoa(prg->ply.steps);
	str = ft_strjoin("Movement count: ", steps);
	mlx_string_put(prg->mlx, prg->win.win, 10, 15, WHITE, str);
	free(steps);
	free(str);
}
