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

static int	ft_is_blank_line(char *line)
{
	int		i;

	i = 0;
	while (line[i] != '\0')
	{
		if (line[i] != ' ' && line[i] != '\t'
			&& line[i] != '\n' && line[i] != '\r')
			return (0);
		i++;
	}
	return (1);
}

static int	ft_is_map_start(char *line)
{
	int		i;

	i = 0;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (line[i] == '\0' || line[i] == '\n' || line[i] == '\r')
		return (0);
	if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
		&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W')
		return (0);
	while (line[i] != '\0' && line[i] != '\n' && line[i] != '\r')
	{
		if (line[i] != '0' && line[i] != '1' && line[i] != 'N'
			&& line[i] != 'S' && line[i] != 'E' && line[i] != 'W'
			&& line[i] != ' ' && line[i] != '\t')
			return (0);
		i++;
	}
	return (1);
}

int	ft_check_form(int fd, t_map_sett *map_sett)
{
	char	*line;
	int		count;

	count = 0;
	while (count < 6)
	{
		line = get_next_line(fd, 0);
		if (!line)
			break ;
		if (ft_is_blank_line(line))
		{
			free(line);
			continue ;
		}
		if (ft_is_map_start(line))
		{
			free(line);
			break ;
		}
		if (ft_fill_textures(line, map_sett) == 0)
			return (free(line), 1);
		free(line);
		count++;
	}
	return (count < 6 || ft_check_data(map_sett));
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
