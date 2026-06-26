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


static void	ft_load_game_data(t_game_instance *game_init, t_map_sett *map_sett)
{
	game_init->mlx_ptr = mlx_init();
	if (!game_init->mlx_ptr)
		clean_exit(map_sett, 6);
	ft_addcf(game_init, map_sett);
	ft_load_text(game_init, map_sett);
	ft_sett_addr(game_init, map_sett);
	ft_copy_map(game_init, map_sett);

}

int	main(int argc, char **argv)
{
	t_map_sett		*map_sett;
	t_game_instance	*game_init;

	if (argc != 2)
		return (ft_print_error(1), 1);
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

