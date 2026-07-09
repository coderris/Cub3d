/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 22:23:43 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/09 20:52:46 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void	ft_move(t_game_instance *game, double delta, double dx, double dy)
{
	double  new_x;
	double  new_y;
	double  mov_spd;

	mov_spd = delta * K_m;
	new_x = game->map_data.player.x + dx * mov_spd;
	new_y = game->map_data.player.y + dy * mov_spd;
	if (game->map_data.map.grid[(int)game->map_data.player.y][(int)new_x] &&
		game->map_data.map.grid[(int)game->map_data.player.y][(int)new_x] != '1')
	{
		game->map_data.player.x = new_x; //este propriedad está nueva
		game->map_data.player.map_x = new_x;
	}
	if (game->map_data.map.grid[(int)new_y][(int)game->map_data.player.x] &&
	game->map_data.map.grid[(int)new_y][(int)game->map_data.player.x] != '1')
	{
		game->map_data.player.y = new_y; //este propriedad está nueva 
		game->map_data.player.map_y = new_y;
	}
}

static void    ft_rotate(t_game_instance *game, double delta)
{
    double  dirx_hldr;
    double  diry_hldr;
    double  plnx_hldr;
    double  plny_hldr;
    double  theta;

    theta = delta * K_r;
    dirx_hldr = game->map_data.player.dir_x;
    diry_hldr = game->map_data.player.dir_y;
    plnx_hldr = game->map_data.player.plane_x;
    plny_hldr = game->map_data.player.plane_y;
    game->map_data.player.dir_x = cos(theta)*dirx_hldr - sin(theta)*diry_hldr;
    game->map_data.player.dir_y = sin(theta)*dirx_hldr + cos(theta)*diry_hldr;
    game->map_data.player.plane_x = cos(theta)*plnx_hldr - sin(theta)*plny_hldr;
    game->map_data.player.plane_y = sin(theta)*plnx_hldr + cos(theta)*plny_hldr;
}

void    ft_handle_movement(t_game_instance *game, double delta)
{
    if (game->map_data.keys.w)
        ft_move(game, delta, game->map_data.player.dir_x, game->map_data.player.dir_y);
    if (game->map_data.keys.a)
        ft_move(game, delta, (-1)*game->map_data.player.plane_x, (-1)*game->map_data.player.plane_y);
    if (game->map_data.keys.s)
        ft_move(game, delta, (-1)*game->map_data.player.dir_x, (-1)*game->map_data.player.dir_y);
    if (game->map_data.keys.d)
        ft_move(game, delta, game->map_data.player.plane_x, game->map_data.player.plane_y);
    if (game->map_data.keys.left)
        ft_rotate(game, -delta);
    if (game->map_data.keys.right)
        ft_rotate(game, delta);
}

