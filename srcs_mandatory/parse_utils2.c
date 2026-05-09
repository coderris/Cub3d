/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/09 01:02:44 by lanton-m          #+#    #+#             */
/*   Updated: 2026/05/09 14:28:34 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (!str || !str[0])
		return (0);
	if (str[i] == '+' || str[i] == '-')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_free_strarr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

int	ft_strarr_len(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}
//larga función
int	*ft_take_nums(char *line)
{
	char	**nums_c;
	int		*nums;
	int		i;

	nums = malloc(sizeof(int) * 3);
	if (!nums)
		return (NULL);
	if (*line != ' ')
		return (free(nums), NULL);
	while (*line == ' ')
		line++;
	if (!*line)
		return (free(nums), NULL);
	nums_c = ft_split(line, ',');
	if (!nums_c || ft_strarr_len(nums_c) != 3)
		return (ft_free_strarr(nums_c), free(nums), NULL);
	i = 0;
	while (nums_c[i])
	{
		if (!ft_isnumeric(nums_c[i]))
			return (ft_free_strarr(nums_c), free(nums), NULL);
		nums[i] = ft_atoi(nums_c[i]);
		if (nums[i] < 0 || nums[i] > 255)
			return (ft_free_strarr(nums_c), free(nums), NULL);
		i++;
	}
	ft_free_strarr(nums_c);
	return (nums);
}
