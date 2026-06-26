/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:31:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/06/26 21:42:13 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void    ft_events(t_game_instance *game)
{
    mlx_hook(game->win_ptr, 2, 1L << 0, ft_key_press, game);
    mlx_hook(game->win_ptr, 3, 1L << 1, ft_key_release, game);
    mlx_hook(game->win_ptr, 17, 1L << 17, ft_close_win, game);
}

double   ft_get_time(void)
{
    struct timeval  tv;
    
    gettimeofday(&tv, NULL);
    return (tv.tv_sec + tv.tv_usec/1000000);
}


static int ft_render(t_game_instance *game)
{
    double  delta;

    game->map_data.player.time = ft_get_time();
    delta = game->map_data.player.time - game->map_data.player.old_time;
    ft_handle_movement(game, delta);
    ft_cast_rays(game);
    ft_draw_frame(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.img, 0, 0);
    game->map_data.player.old_time = game->map_data.player.time;
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

