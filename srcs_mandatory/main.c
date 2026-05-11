/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:42:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/05 21:42:00 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"



int	main(int argc, char **argv)
{
	t_map_sett		*map_sett;
	t_game_instance	*game_init;

	if (argc != 2)
		return (printf("Usage: ./cub3d *.cub\n"), 1);
	map_sett = malloc(sizeof(t_map_sett));
	if (!map_sett)
		return (ft_print_error(5), 1);
	ft_sett_init(map_sett);
	if (ft_parse_map(argv[1], &map_sett))
		return (clean_exit(map_sett, 0), 1);
	game_init = malloc(sizeof(t_game_instance));
	if (!game_init)
		return (ft_print_error(5));
	ft_mapstr_init(game_init);
	ft_load_game_data(game_init, map_sett);
	ft_start_game(game_init);
	
	clean_exit(map_sett, 0);
	return (0);
}

void	ft_load_game_data(t_game_instance *game_init, t_map_sett *map_sett)
{
	ft_addcf(game_init, map_sett);
	ft_load_text(game_init, map_sett);
	ft_sett_addr(game_init, map_sett);
	ft_copy_map(game_init, map_sett);

}
void	ft_copy_map(t_game_instance *game_init, t_map_sett *map_sett)
{
	
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
	{
		ft_print_error(7);
		ft_general_clean();
	}
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
		ft_general_clean(7);
}
