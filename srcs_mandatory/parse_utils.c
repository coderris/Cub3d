/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:02:44 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/09 01:02:44 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	*ft_add_colors(char *line, t_map_sett *map_sett)
{
	int	*numbers;

	numbers = ft_take_nums(line + 1);
	if (!numbers)
	{
		free(line);
		clean_exit(map_sett, 4);
	}
	return (numbers);
}

int	ft_fill_textures(char *line, t_map_sett *map_sett)
{
	if (!ft_strncmp(line, NORTH, 2))
		return (map_sett->n_text = ft_add_text(line, map_sett,
				map_sett->n_text, NORTH), 1);
	if (!ft_strncmp(line, SOUTH, 2))
		return (map_sett->s_text = ft_add_text(line, map_sett,
				map_sett->s_text, SOUTH), 1);
	if (!ft_strncmp(line, WEST, 2))
		return (map_sett->w_text = ft_add_text(line, map_sett,
				map_sett->w_text, WEST), 1);
	if (!ft_strncmp(line, EAST, 2))
		return (map_sett->e_text = ft_add_text(line, map_sett,
				map_sett->e_text, EAST), 1);
	if (!ft_strncmp(line, CEILING, 1))
		return (map_sett->ceiling = ft_add_colors(line, map_sett), 1);
	if (!ft_strncmp(line, FLOOR, 1))
		return (map_sett->floor = ft_add_colors(line, map_sett), 1);
	return (0);
}

char	*ft_add_text(char *line, t_map_sett *map_sett, char *texture, char *dir)
{
	char	*path;
	char	*result;

	path = ft_check_line(line + 2);
	if (texture || path == NULL)
	{
		free(line);
		clean_exit(map_sett, 4);
	}
	result = ft_strdup(path);
	free(path);
	if (!ft_strcmp("NO", dir))
		return (result);
	else if (!ft_strcmp("SO", dir))
		return (result);
	else if (!ft_strcmp("WE", dir))
		return (result);
	else if (!ft_strcmp("EA", dir))
		return (result);
	clean_exit(map_sett, 4);
	return (NULL);
}

static char	*ft_clean_path(char *old_path)
{
	char	*path;

	if (!old_path)
		return (NULL);
	path = ft_strtrim(old_path, " \t\n\r");
	return (path);
}

char	*ft_check_line(char *line)
{
	char	*path;

	path = NULL;
	if (*line != ' ')
		return (path);
	while (*line == ' ')
		line++;
	if (*line && *line == '.')
		path = line;
	return (ft_clean_path(path));
}
