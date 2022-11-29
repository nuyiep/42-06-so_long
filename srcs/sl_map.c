/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:48:05 by plau              #+#    #+#             */
/*   Updated: 2022/11/29 20:56:25 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check extension .ber */
void	check_map(t_prg *prg, int ac, char **av)
{
	if (ac != 2)
		exit_fail("No path to map");
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4) != 0)
		exit_fail("Invalid map extension");
	(void)prg;
}