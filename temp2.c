char	*open_file(char *path, int fd)
{
	char	*str;

	fd = open(path, O_RDONLY);
	if (fd == -1)
		exit_fail("Fail to open file");
	str = get_next_line(fd);
	if (str == NULL)
		exit_fail("Empty map");
	return (str);
}

/* Open file in order to check every line */
void	check_each_line(t_prg *prg, char *path)
{
	char	*str;
	int		fd;
	char	*map_str;

	fd = 0;
	str = open_file(path, fd);
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