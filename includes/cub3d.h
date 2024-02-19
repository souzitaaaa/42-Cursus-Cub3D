#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <string.h>

# define SCREEN_X 1024
# define SCREEN_Y 512
# define FOV 60 // field of view

# if OS == 1
#  include "../minilibx-linux/mlx.h"
#  define ESC 65307
#  define LEFT 65361
#  define RIGHT 65363
#  define UP 65362
#  define DOWN 65364
#  define SHIFT_RIGHT 65506
#  define CTRL_RIGHT 65508
#  define W 119
#  define A 97
#  define S 115
#  define D 100
#  define SHIFT_LEFT 65505
#  define CTRL_LEFT 65507
#  define TAB 65289
#  define INCREASE 43
#  define DECREASE 45
#  define R 114
#  define L 108
#  define H 104
# elif OS == 2
# include "../minilibx/mlx.h"
#  define ESC 53
#  define LEFT 123
#  define RIGHT 124
#  define UP 126
#  define DOWN 125
#  define SHIFT_RIGHT
#  define CTRL_RIGHT
#  define W 13
#  define A 0
#  define S 1
#  define D 2
#  define SHIFT_LEFT
#  define CTRL_RIGHT
#  define TAB
#  define INCREASE 24
#  define DECREASE 27
#  define R 15
#  define L
#  define H
# endif

typedef struct s_map
{
	char	*map_folder;
	int		fd;
	char	**area;
	int		map_y;
	int		map_x;
	int		dir_x;
	int		dir_y;
	int		plane_x;
	int		plane_y;
	double	*ray_dir_x; // array raios x
	double	*ray_dir_y; // array raios y
	double	*ray_pos_x; // array coordenada do raio x
	double	*ray_pos_y; // array coordenada do raio x
}				t_map;

typedef struct s_game
{
	t_map map;
}				t_game;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int	bits_per_pixel;
	int	line_lenght;
	int	endian;
}				t_data;

typedef struct s_vars
{
	void	*mlx;
	void	*win;
}				t_vars;

typedef	struct s_playerPos {
	int		row;
	int		col;
	char	orientation;
} t_playerPos;


//* [src/map_check.c]
void map_validations(t_game *game);
t_playerPos	get_position(t_map *map);
void	set_direction(t_game *game, t_playerPos position);
void	calculate_rays(t_game *game);
void	render_rays(t_game *game);

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);

#endif