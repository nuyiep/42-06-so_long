/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:46:22 by plau              #+#    #+#             */
/*   Updated: 2022/12/06 13:18:58 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

int	exit_success(void)
{
	ft_printf("Thanks for playing\n");
	system("leaks -q so_long");
	exit(0);
	return (0);
}

int	exit_fail(char *error)
{
	ft_printf("ERROR: %s\n", error);
	system("leaks -q so_long");
	exit(1);
	return (1);
}
