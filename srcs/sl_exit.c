/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:46:22 by plau              #+#    #+#             */
/*   Updated: 2022/11/29 18:28:32 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

int	exit_success(void)
{
	ft_printf("YAY YOU WON\n");
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
