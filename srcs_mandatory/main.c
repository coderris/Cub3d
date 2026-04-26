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
	map_sett->N_text = NULL;
	map_sett->S_text = NULL;
	map_sett->W_text = NULL;
	map_sett->E_text = NULL;
	map_sett->Floor = malloc(sizeof(int) * 3);
	map_sett->Ceiling = malloc(sizeof(int ) * 3);
	if (!map_sett->Floor || !map_sett->Ceiling)
		clean_exit(&map_sett, 5);
}

int	main(int argc, char **argv)
{
	t_map_sett *map_sett;

	if (argc != 2)
		return (printf("Usage: ./cub3d *.cub\n"), 1);
	map_sett = malloc(sizeof(t_map_sett));
	ft_sett_init(&map_sett);
	if (ft_parse_map(argv[1], &map_sett))
		return (1);
}
