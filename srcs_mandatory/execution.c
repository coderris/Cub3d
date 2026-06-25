/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:31:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/06/25 01:33:48 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void    ft_events(t_game_instance *game)
{
    mlx_hook(game->win_ptr, 2, 1L << 0, ft_key_press, game);
    mlx_hook(game->win_ptr, 3, 1L << 1, ft_key_release, game);
    mlx_hook(game->win_ptr, 17, 1L << 17, ft_close_win, game);
}
void    ft_start_game(t_game_instance *game)
{
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
    game->screen.img = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp,
                            &game->screen.line_len, &game->screen.endian);
    ft_events(game);
    mlx_loop_hook(game->mlx_ptr, ft_render, game);
    
}

