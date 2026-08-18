/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/18 22:14:07 by lanton-m          #+#    #+#             */
/*   Updated: 2026/08/18 22:19:39 by lanton-m         ###   ########.fr       */
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
		if (map[i][j] != '1'
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
