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
	ft_print_error(err_cod);
	exit(err_cod);
}