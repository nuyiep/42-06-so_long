/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/04 18:26:48 by plau              #+#    #+#             */
/*   Updated: 2022/11/26 18:59:01 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	char	*output;
	size_t	i;

	i = 0;
	output = malloc(nitems * size);
	if (output == NULL || size == SIZE_MAX)
		return (NULL);
	while (i < (nitems * size))
	{
		output[i] = 0;
		i++;
	}
	return ((void *)output);
}
