/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 22:01:33 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/05 22:01:33 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_print_error(int err_code)
{
	if (err_code == 1)
		printf("Error:\nUsage: ./cub3d *.cub\n");
	else if (err_code == 2)
		printf("Error:\nCheck your map extension\n");
	else if (err_code == 3)
		printf("Error:\nCheck your map\n");
	else if (err_code == 4)
		printf("Error:\nCheck your map settings\n");
	else if (err_code == 5)
		printf("Error:\nMalloc error\n");
	else if (err_code == 6)
		printf("Error:\nmlx error\n");
	else if (err_code == 7)
		printf("Error:\nLoading textures\n");
	else
		printf("Error:\nOther error\n");
	return (0);
}