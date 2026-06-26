/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lanton-m <lanton-m@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/05 21:47:01 by lanton-m          #+#    #+#             */
/*   Updated: 2026/04/05 21:47:01 by lanton-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
#define CUB_H

# include "../libs/libft/includes/libft.h"
# include "../libs/mlx/mlx.h"
# include <fcntl.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>

# define WIN_WIDTH 1024
# define WIN_HEIGHT 768
# define NORTH "NO"
# define SOUTH "SO"
# define WEST "WE"
# define EAST "EA"
# define FLOOR "F"
# define CEILING "C"
# define WALL '1'
# define EMPTY '0'

# define ESC 65307
# define W 119
# define UP 65362
# define A 97
# define LEFT 65361
# define S 115
# define DOWN 65364
# define D 100
# define RIGHT 65363

# define K_m 3.00
# define K_r 2.00

typedef struct s_map
{
	char	**grid;
	int		width;
	int		height;
}	t_map;

typedef struct s_map_sett
{
	char	**map;
	char	*n_text;
	char	*s_text;
	char	*w_text;
	char	*e_text;
	int		*floor;
	int		*ceiling;
}	t_map_sett;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
}	t_rgb;

typedef struct s_img
{
	void		*img;
	char		*addr;
	int			width;
	int			height;
	int			bpp;
	int			line_len;
	int			endian;
}	t_img;

typedef struct s_textures
{
	t_img	no;
	t_img	so;
	t_img	we;
	t_img	ea; 
}	t_textures;

typedef struct s_keys
{
	int	w;
	int	a;
	int	s;
	int	d;
	int	left;
	int	right;
}	t_keys;

typedef struct s_game_info
{
	double	x;
	double	y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	time;
	double	old_time;
}	t_game_info;

typedef struct s_game
{
	t_textures	textures;

	t_rgb		floor;
	t_rgb		ceiling;

	t_map		map;
	t_game_info	player;
	t_keys		keys;

	char		*name_window;
	char		*name_map;
}	t_game;

typedef struct s_game_instance
{
	void		*mlx_ptr;
	void		*win_ptr;
	t_img		screen;
	t_game		map_data;
}	t_game_instance;

//ACTIONS.C

void	ft_handle_movement(t_game_instance *game, double delta);
void    ft_move(t_game_instance *game, double delta, double dx, double dy);

//CALLBACKS.C

int	ft_key_press(int keycode, t_game_instance *game);
int ft_key_release(int keycode, t_game_instance *game);
int	ft_close_win(int keycode, t_game_instance *game);

// CLEANERS.C

void	clean_exit(t_map_sett *map_sett, int err_cod);
void	free_matrix(char **matrix);
void	ft_general_clean(t_game_instance *game, int err_cod);

// ERROR_MESSAGE.C

int	ft_print_error(int err_code);

// EXECUTION.C
void		ft_start_game(t_game_instance *game);
double		ft_get_time(void);

//PARSE_MAP1.C

int		ft_check_map(int fd, t_map_sett *map_sett);

//PARSE_MAP2.C

int		ft_check_player(t_map_sett *map_sett);
int		ft_check_invalid_char(t_map_sett *map_sett);
int		ft_check_ext(char *map);
int		ft_check_pos(char **map, int col, int row);

// PARSE_UTILS.C

int		ft_fill_textures(char *line, t_map_sett *map_sett);

//PARSE_UTILS2.C

int		*ft_take_nums(char *line);

// PARSE.C

int		ft_parse_map(char *map, t_map_sett *map_sett);
char	**resize_map(char **old_map, int old_size, char *new_line);

// STRUCT_INIT.C

void	ft_sett_init(t_map_sett *map_sett);
void	ft_mapstr_init(t_game_instance *game);
void	ft_copy_map(t_game_instance *game_init, t_map_sett *map_sett);
void	ft_addcf(t_game_instance *game_init, t_map_sett *map_sett);
void	ft_load_text(t_game_instance *game_init, t_map_sett *map_sett);
void	ft_sett_addr(t_game_instance *game_init, t_map_sett *map_sett);

#endif