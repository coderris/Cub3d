/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:45:57 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/05 21:45:57 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

static int	ft_check_form(int fd, t_map_sett *map_sett)
{
	char		*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		if (ft_strncmp(line, "\n", 2))
		{
			if (ft_fill_textures(line, &map_sett))
				free(line);
		}
		free(line);
	}
	if (ft_check_data(&map_sett))
		clean_exit(&map_sett);
	return (0);
}

static int	ft_check_ext(char *map)
{
	char	*ext;
	char	*input_ext;
	int		i;

	ext = ".cub";
	i = 0;
	input_ext = ft_strrchr((const)map, '.');
	if (ft_strncmp(ext, input_ext, (size_t)ft_strlen(ext)))
		return (1);
	return (0);
}

int	ft_parse_map(char *map, t_map_sett *map_sett)
{
	int	fd;

	if (ft_check_ext(map))
		return (ft_print_error(1), 1);
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return (1);
	if (ft_check_form(fd, &map_sett))
		return (ft_print_error(3), 1);
}
