/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:45:57 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/05 21:45:57 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_form(int fd, t_map_sett *map_sett)
{
	char	*line;
	int		count;
	int		filled;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "\n", 1))
		{
			free(line);
			continue ;
		}
		filled = ft_fill_textures(line, map_sett);
		free(line);
		if (filled == 0)
			return (1);
		count++;
	}
	if (count < 6 || ft_check_data(map_sett))
		return (1);
	return (0);
}

char	**resize_map(char **old_map, int old_size, char *new_line)
{
	int		i;
	char	**new_map;

	new_map = malloc(sizeof(char *) * (old_size + 2));
	if (!new_map)
		return (NULL);
	i = 0;
	while (i < old_size)
	{
		new_map[i] = old_map[i];
		i++;
	}
	new_map[old_size] = new_line;
	new_map[old_size + 1] = NULL;
	free(old_map);
	return (new_map);
}

static int	ft_check_closed_aux(char **map, int i)
{
	int		j;
	int		pos;

	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1' && map[i][j] != '\0'
				&& ft_special_character(map[i][j]))
			return (1);
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (ft_valid_char(map, map[i][j], i, j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_closed(t_map_sett *map_sett)
{
	if (ft_check_closed_aux(map_sett->map, 0) == 1)
		return (1);
	else
		return (0);
}

int	ft_parse_map(char *map, t_map_sett *map_sett)
{
	int	fd;

	if (ft_check_ext(map))
		return (2);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (9);
	if (ft_check_form(fd, map_sett))
		return (close(fd), 4);
	if (ft_check_map(fd, map_sett))
		return (close(fd), 3);
	close(fd);
	return (0);
}
