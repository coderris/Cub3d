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

static int	ft_isnumeric(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] == ' ')
		i++;
	if (str[i] < '0' || str[i] > '9')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\n')
		i++;
	return (str[i] == '\0');
}

static void	ft_free_strarr(char **arr)
{
	int	i;

	if (!arr)
		return ;
	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static int	ft_strarr_len(char **arr)
{
	int	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

static int	*ft_take_nums_aux(char **nums_c, int *nums)
{
	int	i;

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
	return (nums);
}

int	*ft_take_nums(char *line)
{
	char	**nums_c;
	int		*nums;

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
	nums = ft_take_nums_aux(nums_c, nums);
	if (nums == NULL)
		return (NULL);
	ft_free_strarr(nums_c);
	return (nums);
}
