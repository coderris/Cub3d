/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:31:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/02 22:38:32 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static void    ft_events(t_game_instance *game)
{
    mlx_hook(game->win_ptr, 2, 1L << 0, (int (*)())ft_key_press, game);
    mlx_hook(game->win_ptr, 3, 1L << 1, (int (*)())ft_key_release, game);
    mlx_hook(game->win_ptr, 17, 1L << 17, (int (*)())ft_close_win, game);
}

static void    ft_step_side(t_game_instance *game)
{
    if (game->dda.ray_x_dir < 0)
    {
        game->dda.stepX = -1;
        game->dda.sid_dist_X = (game->map_data.player.x - game->dda.x) * game->dda.delt_dist_X;
    }
    else
    {
        game->dda.stepX = 1;
        game->dda.sid_dist_X = (game->dda.x + 1 - game->map_data.player.x) * game->dda.delt_dist_X;
    }
    if (game->dda.ray_y_dir < 0)
    {
        game->dda.stepY = -1;
        game->dda.sid_dist_Y = (game->map_data.player.y - game->dda.y) * game->dda.delt_dist_Y;
    }
    else
    {
        game->dda.stepY = 1;
        game->dda.sid_dist_Y = (game->dda.y + 1 - game->map_data.player.y) * game->dda.delt_dist_Y;
    }
}

static void    ft_dda(t_game_instance *game)
{
    while (game->dda.hit == 0)
    {
        if (game->dda.sid_dist_X < game->dda.sid_dist_Y)
        {
            game->dda.sid_dist_X += game->dda.delt_dist_X;
            game->dda.x += game->dda.stepX;
            game->dda.side = 0;
        }
        else
        {
            game->dda.sid_dist_Y += game->dda.delt_dist_Y;
            game->dda.y += game->dda.stepY;
            game->dda.side = 1;
        }
        if (game->dda.x < 0 || game->dda.y < 0
            || game->dda.y >= game->map_data.map.height
            || game->dda.x >= game->map_data.map.width)
            game->dda.hit = 1;
        else if (game->map_data.map.grid[(int)game->dda.y][(int)game->dda.x] == WALL)
            game->dda.hit = 1;
    }
}

static void    ft_cast_rays(t_game_instance *game)
{
    double  x;
    double  camera_x;

    x = 0;
    while (x <= (WIN_WIDTH - 1))
    {
        ft_dda_init(game);
        camera_x = 2.00 * x / WIN_WIDTH -1;
        game->dda.ray_x_dir = game->map_data.player.dir_x + game->map_data.player.plane_x * camera_x;
        game->dda.ray_y_dir = game->map_data.player.dir_y + game->map_data.player.plane_y * camera_x;
        if (game->dda.ray_x_dir == 0)
            game->dda.delt_dist_X = 1e30;
        else
            game->dda.delt_dist_X = fabs(1 / game->dda.ray_x_dir);
        if (game->dda.ray_y_dir == 0)
            game->dda.delt_dist_Y = 1e30;
        else
            game->dda.delt_dist_Y = fabs(1 / game->dda.ray_y_dir);
        ft_step_side(game);
        ft_dda(game);
        ft_set_rays(game, x);
        x++;
    }
}

int ft_render(t_game_instance *game)
{
    double  delta;

    game->map_data.player.time = ft_get_time();
    delta = game->map_data.player.time - game->map_data.player.old_time;
    ft_handle_movement(game, delta);
    ft_cast_rays(game);
    ft_draw_frame(game);
    mlx_put_image_to_window(game->mlx_ptr, game->win_ptr, game->screen.img, 0, 0);
    game->map_data.player.old_time = game->map_data.player.time;
    return (0);
}

void    ft_start_game(t_game_instance *game)
{
    game->win_ptr = mlx_new_window(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "CUB3D");
    if (!game->win_ptr)
        ft_general_clean(game, 6);
    game->screen.img = mlx_new_image(game->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
    if (!game->screen.img)
        ft_general_clean(game, 6);
    game->screen.addr = mlx_get_data_addr(game->screen.img, &game->screen.bpp,
                            &game->screen.line_len, &game->screen.endian);
    if (!game->screen.addr)
        ft_general_clean(game, 6);
    ft_events(game);
    mlx_loop_hook(game->mlx_ptr, (int (*)())ft_render, game);
    mlx_loop(game->mlx_ptr);
}

