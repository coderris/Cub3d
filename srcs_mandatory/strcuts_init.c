/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strcuts_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:27:32 by lanton-m          #+#    #+#             */
/*   Updated: 2026/05/10 20:25:02 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

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
	game->screen.img = NULL;
	game->screen.addr = NULL;
	game->screen.bpp = 0;
	game->screen.line_len = 0;
	game->screen.endian = 0;
	game->screen.width = 0;
	game->screen.height = 0;
}
