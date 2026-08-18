/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/15 22:02:54 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/15 22:33:31 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	ft_my_pixel_get(t_img *img, int x, int y)
{
	char	*src;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	src = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)src);
}

t_img	*ft_select_texture(t_game_instance *game, t_rays *ray)
{
	if (ray->side == 0)
	{
		if (ray->step_x > 0)
			return (&game->map_data.textures.we);
		return (&game->map_data.textures.ea);
	}
	if (ray->step_y > 0)
		return (&game->map_data.textures.no);
	return (&game->map_data.textures.so);
}

int	ft_get_tex_x(t_game_instance *game, t_rays *ray, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->map_data.player.y + ray->dist * ray->ray_y_dir;
	else
		wall_x = game->map_data.player.x + ray->dist * ray->ray_x_dir;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	if ((ray->side == 0 && ray->ray_x_dir < 0)
		|| (ray->side == 1 && ray->ray_y_dir > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}
