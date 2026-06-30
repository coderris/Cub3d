/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 11:27:32 by lanton-m          #+#    #+#             */
/*   Updated: 2026/06/30 20:12:45 by lanton-m         ###   ########.fr       */
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
	game->map_data.map.grid = NULL;
	game->map_data.player.time = ft_get_time();
	game->map_data.player.old_time = game->map_data.player.time;
	game->screen.bpp = 0;
	game->screen.line_len = 0;
	game->screen.endian = 0;
	game->screen.width = 0;
	game->screen.height = 0;
	game->map_data.keys.w = 0;
	game->map_data.keys.a = 0;
	game->map_data.keys.s = 0;
	game->map_data.keys.d = 0;
	game->map_data.keys.left = 0;
	game->map_data.keys.right = 0;
}

static int	ft_get_max_width(char **map)
{
	int	i;
	int	max;
	int	len;

	i = 0;
	max = 0;
	while (map[i])
	{
		len = ft_strlen(map[i]);
		if (len > 0 && map[i][len - 1] == '\n')
			len--;
		if (len > max)
			max = len;
		i++;
	}
	return (max);
}
int	ft_check_player_let(char c)
{
	if (c == 'N' || c == 'S' || c == 'E' || c == 'W')
		return (1);
	return (0);
}
void	ft_copy_map(t_game_instance *game_init, t_map_sett *map_sett)
{
	int		i;
	int		j;
	int		height;
	int		width;

	height = 0;
	while (map_sett->map[height])
		height++;
	width = ft_get_max_width(map_sett->map);

	game_init->map_data.map.height = height;
	game_init->map_data.map.width = width;

	game_init->map_data.map.grid = malloc(sizeof(char *) * (height + 1));
	if (!game_init->map_data.map.grid)
		ft_general_clean(game_init, 5);

	i = 0;
	while (i < height)
	{
		game_init->map_data.map.grid[i] = malloc(sizeof(char) * (width + 1));
		j = 0;
		while (j < width)
		{
			if (j < (int)ft_strlen(map_sett->map[i]) && map_sett->map[i][j] != '\n')
			{
				if (map_sett->map[i][j] == ' ')
					game_init->map_data.map.grid[i][j] = '1';
				else
				{
				if (ft_check_player(map_sett->map[i][j]))
					{
						game_init->map_data.player.map_x = j;
						game_init->map_data.player.map_y = i;
						game_init->map_data.player.x = j + 0.5;
						game_init->map_data.player.y = i + 0.5;
						game_init->map_data.map.grid[i][j] = '0';
						ft_sett_dir(map_sett->map[i][j], game_init);
					}
					else
						game_init->map_data.map.grid[i][j] = map_sett->map[i][j];
				}
			}
			else
				game_init->map_data.map.grid[i][j] = '1';
			j++;
		}
		game_init->map_data.map.grid[i][width] = '\0';
		i++;
	}
	game_init->map_data.map.grid[height] = NULL;
}
void	ft_sett_dir(char dir, t_game_instance *game)
{
	if (dir == 'N')
	{
		game->map_data.player.dir_x = 0;
		game->map_data.player.dir_y = -1;
		game->map_data.player.plane_x = 0.66;
		game->map_data.player.plane_y = 0;
	}
	else if (dir == 'S')
	{
		game->map_data.player.dir_x = 0;
		game->map_data.player.dir_y = 1;
		game->map_data.player.plane_x = -0.66;
		game->map_data.player.plane_y = 0;
	}
	else if (dir == 'E')
	{
		game->map_data.player.dir_x = 1;
		game->map_data.player.dir_y = 0;
		game->map_data.player.plane_x = 0;
		game->map_data.player.plane_y = 0.66;
	}
	else if (dir == 'W')
	{
		game->map_data.player.dir_x = -1;
		game->map_data.player.dir_y = 0;
		game->map_data.player.plane_x = 0;
		game->map_data.player.plane_y = -0.66;
	}
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

void	ft_load_text(t_game_instance *game_init, t_map_sett *map_sett)
{
	game_init->map_data.textures.no.img = mlx_xpm_file_to_image(game_init->mlx_ptr, map_sett->n_text,
		&game_init->map_data.textures.no.width,
		&game_init->map_data.textures.no.height);
	game_init->map_data.textures.so.img = mlx_xpm_file_to_image(game_init->mlx_ptr, map_sett->n_text,
		&game_init->map_data.textures.so.width,
		&game_init->map_data.textures.so.height);
	game_init->map_data.textures.we.img = mlx_xpm_file_to_image(game_init->mlx_ptr, map_sett->n_text,
		&game_init->map_data.textures.we.width,
		&game_init->map_data.textures.we.height);
	game_init->map_data.textures.ea.img = mlx_xpm_file_to_image(game_init->mlx_ptr, map_sett->n_text,
		&game_init->map_data.textures.ea.width,
		&game_init->map_data.textures.ea.height);
	if (!game_init->map_data.textures.ea.img || !game_init->map_data.textures.ea.img
		|| !game_init->map_data.textures.ea.img || !game_init->map_data.textures.ea.img)
		ft_general_clean(game_init, 7);
}

void	ft_sett_addr(t_game_instance *game_init, t_map_sett *map_sett)
{
	game_init->map_data.textures.no.addr = mlx_get_data_addr(
		game_init->map_data.textures.no.img,
		&game_init->map_data.textures.no.bpp,
		&game_init->map_data.textures.no.line_len,
		&game_init->map_data.textures.no.endian);
	game_init->map_data.textures.so.addr = mlx_get_data_addr(
		game_init->map_data.textures.so.img,
        &game_init->map_data.textures.so.bpp,
        &game_init->map_data.textures.so.line_len,
        &game_init->map_data.textures.so.endian);
	game_init->map_data.textures.we.addr = mlx_get_data_addr(
        game_init->map_data.textures.we.img,
        &game_init->map_data.textures.we.bpp,
        &game_init->map_data.textures.we.line_len,
        &game_init->map_data.textures.we.endian);
	game_init->map_data.textures.ea.addr = mlx_get_data_addr(
        game_init->map_data.textures.ea.img,
		&game_init->map_data.textures.ea.bpp,
        &game_init->map_data.textures.ea.line_len,
        &game_init->map_data.textures.ea.endian);
	if (!game_init->map_data.textures.ea.img || !game_init->map_data.textures.ea.img
		|| !game_init->map_data.textures.ea.img || !game_init->map_data.textures.ea.img)
		ft_general_clean(game_init, 7);
}

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
