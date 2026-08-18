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

static int	*ft_add_colors(char *line, t_map_sett *map_sett, int *color)
{
	int	*numbers;

	numbers = ft_take_nums(line + 1);
	if (!numbers || color)
	{
		free(line);
		clean_exit(map_sett, 4);
	}
	return (numbers);
}

int	ft_fill_textures(char *line, t_map_sett *map_sett)
{
	char	*trimmed;

	trimmed = line;
	while (*trimmed == ' ' || *trimmed == '\t' || *trimmed == '\r')
		trimmed++;
	if (!ft_strncmp(trimmed, NORTH, 2))
		return (map_sett->n_text = ft_add_text(trimmed, map_sett,
				map_sett->n_text, NORTH), 1);
	if (!ft_strncmp(trimmed, SOUTH, 2))
		return (map_sett->s_text = ft_add_text(trimmed, map_sett,
				map_sett->s_text, SOUTH), 1);
	if (!ft_strncmp(trimmed, WEST, 2))
		return (map_sett->w_text = ft_add_text(trimmed, map_sett,
				map_sett->w_text, WEST), 1);
	if (!ft_strncmp(trimmed, EAST, 2))
		return (map_sett->e_text = ft_add_text(trimmed, map_sett,
				map_sett->e_text, EAST), 1);
	if (!ft_strncmp(trimmed, CEILING, 1))
		return (map_sett->ceiling = ft_add_colors(trimmed, map_sett,
				map_sett->ceiling), 1);
	if (!ft_strncmp(trimmed, FLOOR, 1))
		return (map_sett->floor = ft_add_colors(trimmed, map_sett,
				map_sett->floor), 1);
	return (0);
}

char	*ft_add_text(char *line, t_map_sett *map_sett, char *texture, char *dir)
{
	char	*path;
	char	*result;

	path = ft_check_line(line + 2);
	if (texture || path == NULL)
		clean_exit(map_sett, 4);
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
