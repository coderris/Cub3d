/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs_text.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 23:10:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/15 23:13:45 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_text_paths(t_map_sett *map_sett)
{
	return (access(map_sett->n_text, R_OK) != 0
		|| access(map_sett->s_text, R_OK) != 0
		|| access(map_sett->w_text, R_OK) != 0
		|| access(map_sett->e_text, R_OK) != 0);
}

static void	ft_set_texture_addr(t_img *texture)
{
	texture->addr = mlx_get_data_addr(texture->img, &texture->bpp,
			&texture->line_len, &texture->endian);
}

static void	ft_load_texture_images(t_game_instance *game_init,
	t_map_sett *map_sett)
{
	game_init->map_data.textures.no.img = mlx_xpm_file_to_image(
			game_init->mlx_ptr, map_sett->n_text,
			&game_init->map_data.textures.no.width,
			&game_init->map_data.textures.no.height);
	game_init->map_data.textures.so.img = mlx_xpm_file_to_image(
			game_init->mlx_ptr, map_sett->s_text,
			&game_init->map_data.textures.so.width,
			&game_init->map_data.textures.so.height);
	game_init->map_data.textures.we.img = mlx_xpm_file_to_image(
			game_init->mlx_ptr, map_sett->w_text,
			&game_init->map_data.textures.we.width,
			&game_init->map_data.textures.we.height);
	game_init->map_data.textures.ea.img = mlx_xpm_file_to_image(
			game_init->mlx_ptr, map_sett->e_text,
			&game_init->map_data.textures.ea.width,
			&game_init->map_data.textures.ea.height);
}

void	ft_load_text(t_game_instance *game_init, t_map_sett *map_sett)
{
	if (!map_sett->n_text || !map_sett->s_text
		|| !map_sett->w_text || !map_sett->e_text)
		ft_general_clean(game_init, 7);
	if (ft_check_text_paths(map_sett))
	{
		printf("Error:\nInvalid texture path or no read permissions\n");
		printf("NO: %s\n", map_sett->n_text);
		printf("SO: %s\n", map_sett->s_text);
		printf("WE: %s\n", map_sett->w_text);
		printf("EA: %s\n", map_sett->e_text);
		ft_general_clean(game_init, 7);
	}
	ft_load_texture_images(game_init, map_sett);
	if (!game_init->map_data.textures.no.img
		|| !game_init->map_data.textures.so.img
		|| !game_init->map_data.textures.we.img
		|| !game_init->map_data.textures.ea.img)
		ft_general_clean(game_init, 7);
}

void	ft_sett_addr(t_game_instance *game_init, t_map_sett *map_sett)
{
	(void)map_sett;
	ft_set_texture_addr(&game_init->map_data.textures.no);
	ft_set_texture_addr(&game_init->map_data.textures.so);
	ft_set_texture_addr(&game_init->map_data.textures.we);
	ft_set_texture_addr(&game_init->map_data.textures.ea);
	if (!game_init->map_data.textures.no.addr
		|| !game_init->map_data.textures.so.addr
		|| !game_init->map_data.textures.we.addr
		|| !game_init->map_data.textures.ea.addr)
		ft_general_clean(game_init, 7);
}
