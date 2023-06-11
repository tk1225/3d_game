/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: terabu <terabu@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 12:49:39 by takumasaoka       #+#    #+#             */
/*   Updated: 2023/06/11 12:43:26 by terabu           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef cub3d_H
# define cub3d_H

#include <stdio.h>
# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include "../lib/gnl/get_next_line.h"

#define mapWidth 24
#define mapHeight 24
#define screenWidth 640
#define screenHeight 480
#define SUCCESS 1
#define ERROR 0
#define ESC_KEY 53
#define LEFT_KEY 123
#define RIGHT_KEY 124
#define DOWN_KEY 125
#define UP_KEY 126
#define SPACE_KEY 49
#define ESC_KEY_M1 65307
#define LEFT_KEY_M1 65361
#define RIGHT_KEY_M1 65363
#define DOWN_KEY_M1 65364
#define UP_KEY_M1 65362

# define MOVE_SPEED 1
# define ROT_SPEED 0.5

# define MAX_FILE_COL 100
# define MAX_FILE_ROW 100

typedef struct s_vars t_vars;
typedef struct s_data t_data;
typedef struct s_map t_map;
typedef struct s_file_data t_file_data;

struct s_vars
{
	void	*mlx;
	void	*win;
	t_map	*map;
};

struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_file_data
{
	int fd;
	char *file_path;
	char **line;
	int col;
	int row;
};
struct s_map
{
	t_file_data *file_data;
	char **line;
	double posX;
	double posY;
	double dirX;
	double dirY;
	double planeX;
	double planeY;
	double time;
	double oldTime;
};

void raycasting(t_vars *vars);
int	key_handle(int keycode, t_vars *vars);
int input_file(t_map *map, char *file_path);

// # include <fcntl.h>
// # include <unistd.h>
// # include <stdlib.h>
// # include <limits.h>
// # include<mlx.h>
// # include <stdio.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 100
// # endif

// # define SUCCESS 1
// # define ERROR 0
// # define ESC_KEY 53
// # define LEFT_KEY 123
// # define RIGHT_KEY 124
// # define DOWN_KEY 125
// # define UP_KEY 126
// # define SPACE_KEY 49
// # define ESC_KEY_M1 65307
// # define LEFT_KEY_M1 65361
// # define RIGHT_KEY_M1 65363
// # define DOWN_KEY_M1 65364
// # define UP_KEY_M1 65362
// # define SPACE_KEY_M1 32
// # define LEFT 0
// # define UP 1
// # define RIGHT 2
// # define DOWN 3

// typedef struct s_loc
// {
// 	size_t					row;
// 	size_t					col;
// }		t_loc;

// typedef struct s_mapdata
// {
// 	size_t					row;
// 	size_t					col;
// 	int						error_flag;
// 	int						p_xloc;
// 	int						p_yloc;
// }		t_mapdata;

// typedef struct s_data
// {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// typedef struct s_vars
// {
// 	void	*mlx;
// 	void	*win;
// }				t_vars;

// typedef struct s_player
// {
// 	int		x_loc;
// 	int		y_loc;
// 	t_data	*p_up;
// 	t_data	*p_down;
// 	t_data	*p_right;
// 	t_data	*p_left;
// 	t_data	*p_semi_up;
// 	t_data	*p_semi_down;
// 	t_data	*p_semi_right;
// 	t_data	*p_semi_left;
// 	t_data	*p_closed;
// 	int		direction;
// 	int		moving_direction;
// 	int		move_time;
// }				t_player;

// typedef struct s_number
// {
// 	t_data	*number[10];
// }				t_number;

// typedef struct s_ghost
// {
// 	int		x_loc;
// 	int		y_loc;
// 	int		direction;
// 	t_data	*ghost_img;
// }				t_ghost;

// typedef struct s_map_img
// {
// 	t_data	*wall;
// 	t_data	*portal;
// 	t_data	*foods;
// }				t_map_img;

// typedef struct s_game
// {
// 	int			game_status;
// 	t_vars		*vars;
// 	t_player	*player;
// 	t_ghost		*ghost;
// 	t_mapdata	*mapinfo;
// 	char		**map_index;
// 	t_number	*number;
// 	size_t		frame;
// 	void		*p_now_img;
// 	t_map_img	*map_img;
// }				t_game;

// char			*get_next_line(int fd);
// size_t			ft_strlen(const char *target);
// long long int	ft_strchr_len(const char *s, int c);
// char			*ft_strjoin(char const *s1, char const *s2);
// void			ft_putstr_fd(char *s, int fd);
// char			*ft_strtrim(char const *s1, char const *set);
// int				key_handle(int keycode, t_game *game);
// int				create_trgb(int t, int r, int g, int b);
// void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
// void			window_reflesh(t_game *game, int width, int height);
// void			map_init(t_game *game);
// void			ft_putnbr_fd(int n, int fd);
// void			ft_putnbr_display(int n, t_game *game, int order);
// int				game_start(char **map_index, t_mapdata	map_info);
// void			change_ghost_loc(t_game *game);
// void			change_ghost_direction(t_game *game);
// void			img_read(t_game *game);
// void			free_destroy_game(t_game *game);
// void			*ft_calloc(size_t nmemb, size_t size);
// void			*ft_memset(void *target_input, int insert, size_t num);
// void			get_player_start_loc(t_mapdata	*map_info, char **map_index);
// int				check_move(t_game *game, int x_loc, int y_loc);
// int				error_handle(char **map_index, t_mapdata map_info);
// t_mapdata		measure_mapdata(int fd);
// char			**map_index_init(int fd, t_mapdata map_info);
// void			change_player_img(t_game *game);
// void			change_player_loc(t_game *game);
// int				change_player_direction(t_game *game);
// char			**map_index_copy(t_mapdata map_info, char **map_index);
// void			show_map(t_mapdata	map_info, char **map_index);
// int				check_map(t_mapdata	map_info, char **map_index);
// void			free_map(t_mapdata	map_info, char **map_index);
// void			valid_path_check(size_t row, size_t col, \
// char **map_index, t_mapdata map_info);
// int				check_wall(char **map_index, t_mapdata	map_info);
// int				x_click_handle(t_game *game);
#endif
