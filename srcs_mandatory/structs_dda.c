/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_dda.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:40:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/15 23:13:45 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_dda_init(t_game_instance *game)
{
	game->dda.delt_dist_X = 0;
	game->dda.delt_dist_Y = 0;
	game->dda.hit = 0;
	game->dda.side = 0;
	game->dda.stepX = 0;
	game->dda.stepY = 0;
	game->dda.ray_x_dir = 0;
	game->dda.ray_y_dir = 0;
	game->dda.sid_dist_X = 0;
	game->dda.sid_dist_Y = 0;
	game->dda.x = game->map_data.player.map_x;
	game->dda.y = game->map_data.player.map_y;
}

void	ft_set_rays(t_game_instance *game, int x)
{
	game->rays[x].dist = game->dda.sid_dist_Y - game->dda.delt_dist_Y;
	if (game->dda.side == 0)
		game->rays[x].dist = game->dda.sid_dist_X - game->dda.delt_dist_X;
	game->rays[x].side = game->dda.side;
	game->rays[(int)x].step_x = game->dda.stepX;
	game->rays[(int)x].step_y = game->dda.stepY;
	game->rays[(int)x].ray_x_dir = game->dda.ray_x_dir;
	game->rays[(int)x].ray_y_dir = game->dda.ray_y_dir;
}

int	ft_check_player_let(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
