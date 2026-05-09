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

static int	ft_check_data(t_map_sett *map_sett)
{
	if (!map_sett->n_text || !map_sett->s_text
		|| !map_sett->w_text || !map_sett->e_text)
		return (1);
	if (map_sett->floor[0] < 0 || map_sett->floor[1] < 0
		|| map_sett->floor[2] < 0)
		return (1);
	if (map_sett->ceiling[0] < 0 || map_sett->ceiling[1] < 0
		|| map_sett->ceiling[2] < 0)
		return (1);
	return (0);
}

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
		if (!filled)
			return (1);
		count++;
	}
	if (count < 6 || ft_check_data(map_sett))
		return (1);
	return (0);
}

static char	**resize_map(char **old_map, int old_size, char *new_line)
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
//larga función
static int	ft_check_closed(t_map_sett *map_sett)
{
	int		i;
	int		j;
	int		pos;
	char	**map;

	map = map_sett->map;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] == ' ')
			j++;
		if (map[i][j] != '1' && map[i][j] != '\n' && map[i][j] != '\0')
			return (1);
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!ft_strchr("10 NSEW", map[i][j]))
				return (1);
			pos = 0;
			if (ft_strchr("0NSEW", map[i][j]))
				pos = ft_check_pos(map, j, i);
			if (pos)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_parse_map(char *map, t_map_sett *map_sett)
{
	int	fd;

	if (ft_check_ext(map))
		return (ft_print_error(2), 1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (ft_print_error(2), 1);

	if (ft_check_form(fd, map_sett))
	{
		close(fd);
		return (ft_print_error(4), 1);
	}

	if (ft_check_map(fd, map_sett))
	{
		close(fd);
		return (ft_print_error(3), 1);
	}
	close(fd);
	return (0);
}
