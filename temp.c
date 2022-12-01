/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   temp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/01 12:42:26 by plau              #+#    #+#             */
/*   Updated: 2022/12/01 13:15:02 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Player and enemy cant move into walls- wall is 1 */
void	check_within_map(t_prg *prg)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	while (prg->map.map[i] != NULL)
		i++;
	while (k < i)
	{
		while (prg->map.map[k][j] != '\0')
		{
			if (prg->map.map[k][j] == 1)
				//player and enemy can't move
		}
		k++;
	}
}

/* Count and display movement count */ 