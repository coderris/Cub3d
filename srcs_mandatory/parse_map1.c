/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:45:57 by lanton-m          #+#    #+#             */
/*   Updated: 2026/05/09 14:00:27 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

char	*ft_find_map_start(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (ft_strncmp(line, "\n", 1))
			break ;
		free(line);
	}
	return (line);
}

char	**ft_add_line(char **map, int i, char *line)
{
	char	**tmp;

	tmp = map;
	map = resize_map(map, i, line);
	if (!map)
		free_matrix(tmp);
	return (map);
}

char	**ft_read_map(int fd, char *line)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char *) * 2);
	if (!map)
		return (free(line), NULL);
	i = 0;
	map[i++] = line;
	map[i] = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (!ft_strncmp(line, "\n", 1))
			return (free(line), free_matrix(map), NULL);
		map = ft_add_line(map, i, line);
		if (!map)
			return (NULL);
		i++;
	}
	return (map);
}

int	ft_validate_map(t_map_sett *map_sett)
{
	if (ft_check_invalid_char(map_sett))
		return (1);
	if (ft_check_player(map_sett))
		return (1);
	if (ft_check_closed(map_sett))
		return (1);
	return (0);
}

int	ft_check_map(int fd, t_map_sett *map_sett)
{
	char	*line;

	line = ft_find_map_start(fd);
	if (!line)
		return (1);
	map_sett->map = ft_read_map(fd, line);
	if (!map_sett->map)
		return (1);
	if (ft_validate_map(map_sett))
		return (1);
	return (0);
}

// this function...
// static int	ft_check_map(int fd, t_map_sett *map_sett)
// {
// 	int		i;
// 	char	*line;
// 	char	**map;
// 	char	**tmp;

// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			return (1);
// 		if (!ft_strncmp(line, "\n", 1))
// 		{
// 			free(line);
// 			continue ;
// 		}
// 		break ;
// 	}
// 	map = malloc(sizeof(char *) * 2);
// 	if (!map)
// 	{
// 		free(line);
// 		return (1);
// 	}
// 	i = 0;
// 	map[i++] = line;
// 	map[i] = NULL;
// 	while (1)
// 	{
// 		line = get_next_line(fd);
// 		if (!line)
// 			break ;
// 		if (!ft_strncmp(line, "\n", 1))
// 		{
// 			free(line);
// 			free_matrix(map);
// 			return (1);
// 		}
// 		tmp = map;
// 		map = resize_map(map, i, line);
// 		if (!map)
// 		{
// 			free(line);
// 			free_matrix(tmp);
// 			return (1);
// 		}
// 		i++;
// 	}
// 	map_sett->map = map;
// 	if (ft_check_invalid_char(map_sett))
// 		return (1);
// 	if (ft_check_player(map_sett))
// 		return (1);
// 	if (ft_check_closed(map_sett))
// 		return (1);
// 	return (0);
// }