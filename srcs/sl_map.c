/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plau <plau@student.42.kl>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 18:48:05 by plau              #+#    #+#             */
/*   Updated: 2022/12/01 14:45:05 by plau             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sl.h"

/* Check if the map is rectangular- if no, then exit_fail */
void	check_is_rectangular(int x, char *str)
{
	int	cur_len;

	cur_len = ft_strlen(str) - 1;
	if (x != cur_len)
		exit_fail("Map is not rectangular");
}

/* Check first and last row- if not 1 then exit_fail */
void	check_walls(t_prg *prg)
{
	int	j;

	j = 0;
	while (prg->map.map[0][j] != '\0')
	{
		if (prg->map.map[0][j] != '1')
			exit_fail("Map not surrounded by wall");
		if (prg->map.map[prg->map.size.y - 1][j] != '1')
			exit_fail("Map not surrounded by wall");
		j++;
	}
}

/* Check first and last column if not 1 then exit_fail */
void	check_front_and_back(char *str)
{
	if (str[0] != '1')
		exit_fail("Map not surrounded by wall");
	if (str[ft_strlen(str) - 2] != '1')
		exit_fail("Map not surrounded by wall");
}

/* Open file in order to check every line */
void	check_each_line(t_prg *prg, char *path)
{
	char	*str;
	int		fd;
	char	*map_str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_fail("Fail to open file");
	str = get_next_line(fd);
	prg->map.size.x = ft_strlen(str) - 1;
	map_str = ft_calloc(1, sizeof(char *));
	while (str != NULL)
	{
		map_str = ft_strjoin_free(map_str, str);
		prg->map.size.y++;
		free(str);
		str = get_next_line(fd);
		if (str != NULL)
		{
			check_front_and_back(str);
			check_is_rectangular(prg->map.size.x, str);
		}
	}
	prg->map.map = ft_split(map_str, '\n');
	check_walls(prg);
	free(map_str);
}

/* Main function to check map */
/* Check extension .ber */
void	check_map(t_prg *prg, int ac, char **av)
{
	if (ac != 2)
		exit_fail("No path to map");
	if (ft_strncmp(&av[1][ft_strlen(av[1]) - 4], ".ber", 4) != 0)
		exit_fail("Invalid map extension");
	check_each_line(prg, av[1]);
	get_data(prg);
	check_valid_path(prg);
}
