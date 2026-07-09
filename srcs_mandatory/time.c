/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:19:41 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/07 22:01:50 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

double   ft_get_time(void)
{
    struct timeval  tv;

    gettimeofday(&tv, NULL);
    return ((double)(tv.tv_sec + (double)tv.tv_usec / 1000000.0));
}
