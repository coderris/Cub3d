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

void	clean_exit(t_map_sett *map_sett, int err_cod)
{
	if (map_sett->N_text)
		free(map_sett->N_text);
	if (map_sett->S_text)
		free(map_sett->S_text);
	if (map_sett->W_text)
		free(map_sett->W_text);
	if (map_sett->E_text)
		free(map_sett->E_text);
	if (map_sett->Ceiling)
		free(map_sett->Ceiling);
	if (map_sett->Floor);
		free(map_sett->Floor);
	ft_print_error(err_cod);
	exit(err_cod);
}