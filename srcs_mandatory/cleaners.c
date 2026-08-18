/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 12:56:24 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/09 12:56:24 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix && matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	clean_exit(t_map_sett *map_sett, int err_cod)
{
	int	i;

	i = 0;
	get_next_line(-1, 1);
	if (map_sett->n_text)
		free(map_sett->n_text);
	if (map_sett->s_text)
		free(map_sett->s_text);
	if (map_sett->w_text)
		free(map_sett->w_text);
	if (map_sett->e_text)
		free(map_sett->e_text);
	if (map_sett->ceiling)
		free(map_sett->ceiling);
	if (map_sett->floor)
		free(map_sett->floor);
	if (map_sett->map)
		free_matrix(map_sett->map);
	free(map_sett);
	if (err_cod == 0)
		return ;
	ft_print_error(err_cod);
}

static void	ft_destroy_img(t_game_instance *game)
{
	if (game->screen.img)
		mlx_destroy_image(game->mlx_ptr, game->screen.img);
	if (game->map_data.textures.no.img)
		mlx_destroy_image(game->mlx_ptr, game->map_data.textures.no.img);
	if (game->map_data.textures.so.img)
		mlx_destroy_image(game->mlx_ptr, game->map_data.textures.so.img);
	if (game->map_data.textures.we.img)
		mlx_destroy_image(game->mlx_ptr, game->map_data.textures.we.img);
	if (game->map_data.textures.ea.img)
		mlx_destroy_image(game->mlx_ptr, game->map_data.textures.ea.img);
}

void	ft_general_clean(t_game_instance *game, int err_cod)
{
	get_next_line(-1, 1);
	if (!game)
		return ;
	if (game->mlx_ptr)
	{
		ft_destroy_img(game);
		if (game->win_ptr)
			mlx_destroy_window(game->mlx_ptr, game->win_ptr);
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	free_matrix(game->map_data.map.grid);
	free(game);
	if (err_cod == 0)
		printf("Closing window. Good game\n");
	else
		ft_print_error(err_cod);
}
