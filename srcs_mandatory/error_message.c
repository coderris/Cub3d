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
		printf("Usage: ./cub3d *.cub\n");
	else if (err_code == 2)
		printf("Check your map extension\n");
	else if (err_code == 3)
		printf("Check your map\n");
	else if (err_code == 4)
		printf("Check your map settings\n");
	else if (err_code == 5)
		printf("Malloc error\n");
	
}