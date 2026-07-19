/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 19:07:50 by lanton-m          #+#    #+#             */
/*   Updated: 2026/07/18 22:30:05 by lanton-m         ###   ########.fr       */
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

static void	ft_draw_ceiling(t_game_instance *game, int x,
	int draw_start, t_rgb color)
{
	int	y;
	int	rgb;

	rgb = (color.r << 16) | (color.g << 8) | color.b;
	y = 0;
	while (y < draw_start)
	{
		ft_my_pixel_put(&game->screen, x, y, rgb);
		y++;
	}
}

static void	ft_draw_wall_col(t_game_instance *game, int x,
	int draw_start, int draw_end)
{
	t_img	*tex;
	int		line_h;
	double	step;
	double	tex_pos;
	int		tex_y;

	tex = ft_select_texture(game, &game->rays[x]);
	line_h = (int)(WIN_HEIGHT / game->rays[x].dist);
	step = 1.0 * tex->height / line_h;
	tex_pos = (draw_start - WIN_HEIGHT / 2 + line_h / 2) * step;
	while (draw_start < draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y >= tex->height)
			tex_y = tex->height - 1;
		ft_my_pixel_put(&game->screen, x, draw_start,
			ft_my_pixel_get(tex, ft_get_tex_x(game, &game->rays[x], tex),
				tex_y));
		tex_pos += step;
		draw_start++;
	}
}

static void	ft_draw_floor(t_game_instance *game, int x, int draw_end,
	t_rgb color)
{
	int	y;
	int	rgb;

	rgb = (color.r << 16) | (color.g << 8) | color.b;
	y = draw_end;
	while (y < WIN_HEIGHT)
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
		ft_draw_ceiling(game, x, draw_start, game->map_data.ceiling);
		ft_draw_wall_col(game, x, draw_start, draw_end);
		ft_draw_floor(game, x, draw_end, game->map_data.floor);
		if (x > (int)(WIN_WIDTH/1.50))
			ft_draw_map(game, x)
		x++;
	}
}
