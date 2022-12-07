/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_exit_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 15:46:22 by plau              #+#    #+#             */
/*   Updated: 2022/12/07 15:35:31 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

int	exit_success(void)
{
	ft_printf("Thanks for playing\n");
	exit(0);
	return (0);
}

int	exit_fail(char *error)
{
	ft_printf("ERROR: %s\n", error);
	exit(1);
	return (1);
}
