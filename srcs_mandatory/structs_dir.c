/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_dir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:10:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/15 23:13:45 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_set_north(t_game_instance *game)
{
	game->map_data.player.dir_x = 0;
	game->map_data.player.dir_y = -1;
	game->map_data.player.plane_x = 0.66;
	game->map_data.player.plane_y = 0;
}

static void	ft_set_south(t_game_instance *game)
{
	game->map_data.player.dir_x = 0;
	game->map_data.player.dir_y = 1;
	game->map_data.player.plane_x = -0.66;
	game->map_data.player.plane_y = 0;
}

static void	ft_set_east(t_game_instance *game)
{
	game->map_data.player.dir_x = 1;
	game->map_data.player.dir_y = 0;
	game->map_data.player.plane_x = 0;
	game->map_data.player.plane_y = 0.66;
}

static void	ft_set_west(t_game_instance *game)
{
	game->map_data.player.dir_x = -1;
	game->map_data.player.dir_y = 0;
	game->map_data.player.plane_x = 0;
	game->map_data.player.plane_y = -0.66;
}

void	ft_sett_dir(char dir, t_game_instance *game)
{
	if (dir == 'N')
		ft_set_north(game);
	else if (dir == 'S')
		ft_set_south(game);
	else if (dir == 'E')
		ft_set_east(game);
	else if (dir == 'W')
		ft_set_west(game);
}
