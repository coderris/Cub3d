/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: najlghar <najlghar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:07:50 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/09 20:54:05 by najlghar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

void	ft_my_pixel_put(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= WIN_WIDTH || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_len + x * (img->bpp / 8));
	*(unsigned int *)dst = color;
}

int	ft_my_pixel_get(t_img *img, int x, int y)
{
	char	*src;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return (0);
	src = img->addr + (y * img->line_len + x * (img->bpp / 8));
	return (*(unsigned int *)src);
}

static t_img	*ft_select_texture(t_game_instance *game, t_rays *ray)
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

static int	ft_get_tex_x(t_game_instance *game, t_rays *ray, t_img *tex)
{
	double	wall_x;
	int		tex_x;

	if (ray->side == 0)
		wall_x = game->map_data.player.y + ray->dist * ray->ray_y_dir;
	else
		wall_x = game->map_data.player.x + ray->dist * ray->ray_x_dir;
	wall_x -= floor(wall_x);
	tex_x = (int)(wall_x * tex->width);
	// invertirmos las paredes que no están bien orientadas  
	if ((ray->side == 0 && ray->ray_x_dir < 0)
		|| (ray->side == 1 && ray->ray_y_dir > 0))
		tex_x = tex->width - tex_x - 1;
	return (tex_x);
}

static void	ft_draw_wall_col(t_game_instance *game, int x, t_rays *ray,
	int draw_start, int draw_end)
{
	t_img	*tex;
	int		tex_x;
	int		line_h;
	double	step;
	double	tex_pos;
	int		y;
	int		tex_y;

	tex = ft_select_texture(game, ray);
	tex_x = ft_get_tex_x(game, ray, tex);
	line_h = (int)(WIN_HEIGHT / ray->dist);
	step = 1.0 * tex->height / line_h;
	tex_pos = (draw_start - WIN_HEIGHT / 2 + line_h / 2) * step;
	y = draw_start;
	while (y < draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		ft_my_pixel_put(&game->screen, x, y,
			ft_my_pixel_get(tex, tex_x, tex_y));
		tex_pos += step;
		y++;
	}
}

static void	ft_draw_flat(t_game_instance *game, int x, int from, int to,
	t_rgb color)
{
	int	y;
	int	rgb;

	rgb = (color.r << 16) | (color.g << 8) | color.b;
	y = from;
	while (y < to)
	{
		ft_my_pixel_put(&game->screen, x, y, rgb);
		y++;
	}
}

void	ft_draw_frame(t_game_instance *game)
{
	int	x;
	int	line_h;
	int	draw_start;
	int	draw_end;

	x = 0;
	while (x < WIN_WIDTH)
	{
		line_h = (int)(WIN_HEIGHT / game->rays[x].dist);
		draw_start = -line_h / 2 + WIN_HEIGHT / 2;
		if (draw_start < 0)
			draw_start = 0;
		draw_end = line_h / 2 + WIN_HEIGHT / 2;
		if (draw_end >= WIN_HEIGHT)
			draw_end = WIN_HEIGHT - 1;
		ft_draw_flat(game, x, 0, draw_start, game->map_data.ceiling);
		ft_draw_wall_col(game, x, &game->rays[x], draw_start, draw_end);
		ft_draw_flat(game, x, draw_end, WIN_HEIGHT, game->map_data.floor);
		x++;
	}
}
