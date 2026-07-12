/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   callbacks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/24 21:43:49 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/12 20:18:15 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_key_press(int keycode, t_game_instance *game)
{
	if (keycode == W)
		game->map_data.keys.w = 1;
	else if (keycode == A)
		game->map_data.keys.a = 1;
	else if (keycode == S)
		game->map_data.keys.s = 1;
	else if (keycode == D)
		game->map_data.keys.d = 1;
	else if (keycode == LEFT)
		game->map_data.keys.left = 1;
	else if (keycode == RIGHT)
		game->map_data.keys.right = 1;
	else if (keycode == ESC)
		ft_close_win(0, game);
	return (0);
}

int	ft_key_release(int keycode, t_game_instance *game)
{
	if (keycode == W)
		game->map_data.keys.w = 0;
	else if (keycode == A)
		game->map_data.keys.a = 0;
	else if (keycode == S)
		game->map_data.keys.s = 0;
	else if (keycode == D)
		game->map_data.keys.d = 0;
	else if (keycode == LEFT)
		game->map_data.keys.left = 0;
	else if (keycode == RIGHT)
		game->map_data.keys.right = 0;
	return (0);
}

int	ft_close_win(int ex_val, t_game_instance *game)
{
	ft_general_clean(game, ex_val);
	exit(0);
}
