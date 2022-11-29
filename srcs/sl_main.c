/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 09:26:08 by plau              #+#    #+#             */
/*   Updated: 2022/11/29 18:33:08 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/**
 * Set up so that when any key is pressed, will print "Key pressed"
 * Set up arrow keys, everytime you press up, will print "UP"
 */

/* Start of the main function */
int	main(int ac, char **av)
{	
	t_prg	prg;

	(void)ac;
	(void)av;
	init_game(&prg);
	loop_game(&prg);
	return (exit_success());
}
