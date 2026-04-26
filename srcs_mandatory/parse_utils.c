/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:02:44 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/09 01:02:44 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_fill_textures(char *line, t_map_sett *map_sett)
{
	char	*path;

	if (!ft_strncmp(line, NORTH, 2))
		map_sett->N_text = ft_add_text(line, &map_sett,
				map_sett->N_text, NORTH);
	else if (!ft_strncmp(line, SOUTH, 2))
		map_sett->S_text = ft_add_text(line, &map_sett,
				map_sett->S_text, SOUTH);
	else if (!ft_strncmp(line, WEST, 2))
		map_sett->W_text = ft_add_text(line, &map_sett, map_sett->W_text, WEST);
	else if (!ft_strncmp(line, EAST, 2))
		map_sett->E_text = ft_add_text(line, &map_sett, map_sett->E_text, EAST);
	else if (!ft_strncmp(line, CEILING, 1))
		map_sett->Ceiling = ft_add_colors(line, &map_sett, map_sett->Ceiling, CEILING);
	else if (!ft_strncmp(line, FLOOR, 1))
		map_sett->Floor = ft_add_colors(line, &map_sett, map_sett->Floor, FLOOR);
}

int	*ft_add_colors(char *line, t_map_sett **map_sett, int *rgb, char *room)
{
	int	*numbers;

	if (rgb)
		clean_exit(&map_sett, 5);
	numbers = ft_take_nums(line + 1);
	if (numbers == 0)
		clean_exit(&map_sett, 5);
	return (numbers);
}

static int	*ft_take_nums(char *line)
{
	char	**nums_c;
	int		*nums;
	int		i;

	nums_c = NULL;
	nums = malloc(sizeof(int) * 3);
	i = 0;
	if (*line != ' ')
		return (free(nums), 0);
	while (*line == ' ')
		line++;
	if (*line)
		nums_c = ft_split(line, ',');
	while (nums_c[i])
	{
		nums[i] = ft_atoi(nums_c[i]);
		if (!ft_strcmp(nums_c[i], "0") || nums[i] < 0 || nums[i] > 255)
			return (free(nums_c), 0);
		i++;
	}
	free(nums_c);
	return (nums);
}

char	*ft_add_text(char *line, t_map_sett *map_sett, char *texture, char *dir)
{
	char	*path;

	if (texture)
		clean_exit(&map_sett, 4);
	path = ft_check_line(line + 2);
	if (path == NULL)
		clean_exit(&map_sett, 4);
	if (!ft_strcmp("NO", dir))
		 return(ft_strdup(path));
	else if (!ft_strcmp("SO", dir))
		return(ft_strdup(path));
	else if (!ft_strcmp("WE", dir))
		return(ft_strdup(path));
	else if (!ft_strcmp("EA", dir))
		return(ft_strdup(path));
}

char	*ft_check_line(char *line)
{
	char	*path;

	path = NULL;
	if (*line != ' ')
		return (path);
	while (*line == ' ')
		line++;
	if (*line && *line == '.')
		path = line;
	return (path);
}
