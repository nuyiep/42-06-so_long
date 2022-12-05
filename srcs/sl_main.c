/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:26:08 by plau              #+#    #+#             */
/*   Updated: 2022/12/05 11:53:50 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Start of the main function */
int	main(int ac, char **av)
{	
	t_prg	prg;

	init_game(&prg);
	check_map(&prg, ac, av);
	loop_game(&prg);
	return (exit_success());
}
