/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_copy_map.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:10:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/08/13 20:10:28 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_prepare_map(t_game_instance *game_init, t_map_sett *map_sett)
{
	int	height;
	int	width;
	int	len;
	int	i;

	height = 0;
	while (map_sett->map[height])
		height++;
	width = 0;
	i = 0;
	while (map_sett->map[i])
	{
		len = ft_strlen(map_sett->map[i]);
		if (len > 0 && map_sett->map[i][len - 1] == '\n')
			len--;
		if (len > width)
			width = len;
		i++;
	}
	game_init->map_data.map.height = height;
	game_init->map_data.map.width = width;
	game_init->map_data.map.grid = malloc(sizeof(char *) * (height + 1));
	if (!game_init->map_data.map.grid)
		ft_general_clean(game_init, 5);
}

static void	ft_copy_map_cell(t_game_instance *game, t_map_sett *map_sett,
	int i, int j)
{
	char	cell;
	int		len;

	len = (int)ft_strlen(map_sett->map[i]);
	if (j < len)
		cell = map_sett->map[i][j];
	else
		cell = '\0';
	if (j < len && cell != '\n' && cell != '\0')
	{
		if (cell == ' ')
			game->map_data.map.grid[i][j] = '1';
		else if (ft_strchr("NSEW", cell))
		{
			game->map_data.player.map_x = j;
			game->map_data.player.map_y = i;
			game->map_data.player.x = j + 0.5;
			game->map_data.player.y = i + 0.5;
			game->map_data.map.grid[i][j] = '0';
			ft_sett_dir(cell, game);
		}
		else
			game->map_data.map.grid[i][j] = cell;
	}
	else
		game->map_data.map.grid[i][j] = '1';
}

static void	ft_fill_map_row(t_game_instance *game, t_map_sett *map_sett,
	int i)
{
	int	j;

	j = 0;
	while (j < game->map_data.map.width)
	{
		ft_copy_map_cell(game, map_sett, i, j);
		j++;
	}
	game->map_data.map.grid[i][game->map_data.map.width] = '\0';
}

void	ft_copy_map(t_game_instance *game_init, t_map_sett *map_sett)
{
	int	i;
	int	height;
	int	width;

	ft_prepare_map(game_init, map_sett);
	height = game_init->map_data.map.height;
	width = game_init->map_data.map.width;
	i = 0;
	while (i < height)
	{
		game_init->map_data.map.grid[i] = malloc(sizeof(char) * (width + 1));
		if (!game_init->map_data.map.grid[i])
			ft_general_clean(game_init, 5);
		ft_fill_map_row(game_init, map_sett, i);
		i++;
	}
	game_init->map_data.map.grid[height] = NULL;
}
