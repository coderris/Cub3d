/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:45:57 by lanton-m          #+#    #+#             */
/*   Updated: 2026/05/09 14:20:48 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_is_player(char c)
{
	return (ft_strchr("NSEW", c) != NULL);
}

int	ft_check_player(t_map_sett *map_sett)
{
	int		i;
	int		j;
	int		count;
	char	**map;

	map = map_sett->map;
	count = 0;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != '\0' && map[i][j] != '\n')
		{
			if (ft_is_player(map[i][j]))
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		return (1);
	return (0);
}

int	ft_check_invalid_char(t_map_sett *map_sett)
{
	int		i
	int		j;
	char	**map;

	map = map_sett->map;
	i = 0;
	while (map[i] != NULL)
	{
		j = 0;
		while (map[i][j] != '\n' && map[i][j] != '\0')
		{
			if (!ft_strchr("10 NSEW", map[i][j]))
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_check_ext(char *map)
{
	char	*input_ext;

	input_ext = ft_strrchr(map, '.');
	if (!input_ext)
		return (1);
	if (ft_strncmp(".cub", input_ext, 4) || ft_strlen(input_ext) != 4)
		return (1);
	return (0);
}

int	ft_check_pos(char **map, int col, int row)
{
	int	len_above;
	int	len_below;
	int	len_current;

	len_current = (int)ft_strlen(map[row]);
	if (row == 0)
		return (1);
	if (map[row + 1] == NULL)
		return (1);
	len_above = (int)ft_strlen(map[row - 1]);
	len_below = (int)ft_strlen(map[row + 1]);
	if (col >= len_above || !ft_strchr("10NSEW", map[row - 1][col]))
		return (1);
	if (col >= len_below || !ft_strchr("10NSEW", map[row + 1][col]))
		return (1);
	if (col == 0)
		return (1);
	if (!ft_strchr("10NSEW", map[row][col - 1]))
		return (1);
	if (col + 1 >= len_current || map[row][col + 1] == '\n'
		|| map[row][col + 1] == '\0')
		return (1);
	if (!ft_strchr("10NSEW", map[row][col + 1]))
		return (1);
	return (0);
}
