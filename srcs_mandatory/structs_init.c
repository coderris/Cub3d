/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:27:32 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/15 23:13:45 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_init_game_state(t_game_instance *game)
{
	game->screen.img = NULL;
	game->screen.addr = NULL;
	game->screen.bpp = 0;
	game->screen.line_len = 0;
	game->screen.endian = 0;
	game->screen.width = 0;
	game->screen.height = 0;
	game->map_data.textures.no.img = NULL;
	game->map_data.textures.so.img = NULL;
	game->map_data.textures.we.img = NULL;
	game->map_data.textures.ea.img = NULL;
	game->map_data.textures.no.addr = NULL;
	game->map_data.textures.so.addr = NULL;
	game->map_data.textures.we.addr = NULL;
	game->map_data.textures.ea.addr = NULL;
	game->map_data.map.grid = NULL;
	game->map_data.player.time = ft_get_time();
	game->map_data.player.old_time = game->map_data.player.time;
	game->map_data.keys.w = 0;
	game->map_data.keys.a = 0;
	game->map_data.keys.s = 0;
	game->map_data.keys.d = 0;
	game->map_data.keys.left = 0;
	game->map_data.keys.right = 0;
}

void	ft_sett_init(t_map_sett *map_sett)
{
	map_sett->map = NULL;
	map_sett->n_text = NULL;
	map_sett->s_text = NULL;
	map_sett->w_text = NULL;
	map_sett->e_text = NULL;
	map_sett->floor = NULL;
	map_sett->ceiling = NULL;
}

void	ft_mapstr_init(t_game_instance *game)
{
	game->mlx_ptr = NULL;
	game->win_ptr = NULL;
	ft_init_game_state(game);
}

void	ft_addcf(t_game_instance *game_init, t_map_sett *map_sett)
{
	game_init->map_data.floor.r = map_sett->floor[0];
	game_init->map_data.floor.g = map_sett->floor[1];
	game_init->map_data.floor.b = map_sett->floor[2];
	game_init->map_data.ceiling.r = map_sett->ceiling[0];
	game_init->map_data.ceiling.g = map_sett->ceiling[1];
	game_init->map_data.ceiling.b = map_sett->ceiling[2];
}
