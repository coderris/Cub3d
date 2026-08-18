/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 19:27:02 by lanton-m          #+#    #+#             */
/*   Updated: 2026/08/18 18:08:20 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_special_character(char c)
{
	if (c == '\0')
		return (0);
	if (c == '\n')
		return (0);
	if (c == '\t' || c == '\r' || c == ' ')
		return (0);
	if (c == '\v' || c == '\b')
		return (0);
	return (1);
}

int	ft_check_data(t_map_sett *map_sett)
{
	if (!map_sett->n_text || !map_sett->s_text
		|| !map_sett->w_text || !map_sett->e_text)
		return (1);
	if (map_sett->floor[0] < 0 || map_sett->floor[1] < 0
		|| map_sett->floor[2] < 0)
		return (1);
	if (map_sett->ceiling[0] < 0 || map_sett->ceiling[1] < 0
		|| map_sett->ceiling[2] < 0)
		return (1);
	return (0);
}

int	ft_valid_char(char **map, char c, int i, int j)
{
	int	pos;

	pos = 0;
	if (!ft_strchr("10 NSEW", c)
		&& ft_special_character(c))
		return (1);
	if (ft_strchr("0NSEW", c)
		&& ft_special_character(c))
		pos = ft_check_pos(map, j, i);
	if (pos)
		return (1);
	return (0);
}
