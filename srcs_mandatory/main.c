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

static void	ft_sett_init(t_map_sett *map_sett)
{
	map_sett->map = NULL;
	map_sett->n_text = NULL;
	map_sett->s_text = NULL;
	map_sett->w_text = NULL;
	map_sett->e_text = NULL;
	map_sett->floor = NULL;
	map_sett->ceiling = NULL;
}

static void	ft_mapstr_init(t_game_instace game)
{
	
}

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
	if (ft_parse_map(argv[1], map_sett))
		return (clean_exit(map_sett, 0), 1);
	ft_mapstr_init(game_init);
	clean_exit(map_sett, 0);
	return (0);
}
