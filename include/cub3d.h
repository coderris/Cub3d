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
# include <string.h>
# include <stdio.h>

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

typedef struct s_textures
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea; 
}	t_textures;

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

	char		*name_window;
	char		*name_map;
}	t_game;

typedef struct s_game_instance
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img;
	char		*pixel;
	t_game		map_data;

}	t_game_instance;



// PARSE.C

int		ft_parse_map(char *map, t_map_sett *map_sett);

// PARSE_UTILS.C

int		ft_fill_textures(char *line, t_map_sett *map_sett);
char	*ft_add_text(char *line, t_map_sett *map_sett, char *texture, char *dir);
char	*ft_check_line(char *line);

//parse_utils2.c

int		ft_isnumeric(char *str);
void	ft_free_strarr(char **arr);
int		ft_strarr_len(char **arr);
int		*ft_take_nums(char *line);


//parse_map1.c
char	*ft_find_map_start(int fd);
char	**ft_add_line(char **map, int i, char *line);
char	**ft_read_map(int fd, char *line);
int		ft_validate_map(t_map_sett *map_sett);
int		ft_check_map(int fd, t_map_sett *map_sett);

//parse_map2.c
int		ft_check_player(t_map_sett *map_sett);
int		ft_check_invalid_char(t_map_sett *map_sett);
int		ft_check_ext(char *map);
int		ft_check_pos(char **map, int col, int row);


// ERROR_MESSAGE.C

int	ft_print_error(int err_code);

// CLEANERS.C

void	clean_exit(t_map_sett *map_sett, int err_cod);

#endif