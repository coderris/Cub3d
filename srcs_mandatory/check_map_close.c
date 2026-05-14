/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_close.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/14 20:13:08 by najlghar          #+#    #+#             */
/*   Updated: 2026/05/14 20:13:45 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_closed_aux(char **map, int i)
{
	int		j;
	int		pos;

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

int	ft_check_closed(t_map_sett *map_sett)
{
	int		i;
	char	**map;

	i = 0;
	map = map_sett->map;
	if (ft_check_closed_aux(map, i) == 1)
		return (1);
	else
		return (0);
}