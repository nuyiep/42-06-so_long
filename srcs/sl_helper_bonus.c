/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_helper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/02 18:30:38 by plau              #+#    #+#             */
/*   Updated: 2022/12/06 18:56:15 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Printing map in shell */
void	sl_printmap(t_prg *prg, char **map)
{
	int	j;

	j = -1;
	while (++j < prg->map.size.y)
		ft_printf("%s\n", map[j]);
	ft_printf("\n");
}
