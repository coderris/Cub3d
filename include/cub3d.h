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

#ifndef CUB
#define CUB

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
#define CEILING "C"
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

typedef struct s_map_sett
{
	char	*N_text;
	char	*S_text;
	char	*W_text;
	char	*E_text;
	int		*Floor;
	int		*Ceiling;
} t_map_sett;

typedef struct s_game_info
{
	double	X;
	double	Y;
	double	dir_X;
	double	dir_Y;
	double	plane_X;
	double	plane_Y;
	double	time;
	double	old_time;
} t_game_inf;



// PARSE.C

int		ft_parse_map(char *map, t_map_sett *map_sett);

// PARSE_UTILS.C

int		ft_fill_textures(char *line, t_map_sett *map_sett);
int		ft_add_text(char *line, t_map_sett *map_sett, char *texture, char *dir);
char	*ft_check_line(char *line);

// ERROR_MESSAGE.C

int	ft_print_error(int err_code);

// CLEANERS.C

void	clean_exit(t_map_sett *map_sett, int err_cod);

#endif