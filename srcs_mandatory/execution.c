/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/10 19:31:00 by lanton-m          #+#    #+#             */
/*   Updated: 2026/05/10 19:38:12 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void    ft_start_game(t_game_instance *game)
{
    game->mlx_ptr = mlx_init();
    if (!game->mlx_ptr)
    {
        ft_general_clean();
        ft_print_error(6);   
    }
}