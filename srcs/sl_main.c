/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:26:08 by plau              #+#    #+#             */
/*   Updated: 2022/11/30 22:31:26 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Start of the main function */
int	main(int ac, char **av)
{	
	t_prg	prg;

	check_map(&prg, ac, av);
	init_game(&prg);
	loop_game(&prg);
	return (exit_success());
}
