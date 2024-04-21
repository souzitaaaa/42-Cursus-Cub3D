/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dinoguei <dinoguei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/21 17:24:15 by dinoguei          #+#    #+#             */
/*   Updated: 2024/04/21 23:28:57 by dinoguei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <stdint.h>
# include <string.h>
# include <math.h>

# define SCREEN_X 800
# define SCREEN_Y 400
# define FOV 60
# define MOVESTEP	0.1

# define YELLOW "\033[0;31m"
# define RESET "\033[0m"

# define TEXTURE_X 64

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
#  include "../minilibx/mlx.h"
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

typedef struct s_vector
{
	double	x;
	double	y;
}				t_vector;

typedef struct s_ivector
{
	int		x;
	int		y;
}				t_ivector;

typedef struct s_len_line
{
	int		len_current_line;
	int		len_prev_line;
	int		len_next_line;
}					t_len_line;

typedef struct s_map
{
	char		*map_folder;
	char		*no_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			f_range[3];
	int			c_range[3];
	int			fd;
	char		**area;
	char		**map_a;
	int			mapa_y;
	int			mapa_x;
	int			area_y;
	int			area_x;
	char		*line;
	t_vector	dir;
	t_vector	plane;
}				t_map;

typedef struct s_data
{
	void			*mlx;
	void			*win;
	void			*img;
	unsigned int	*addr;
	int				bits_per_pixel;
	int				line_len;
	int				endian;
}				t_data;

typedef struct s_playerPos
{
	double		row;
	double		col;
	char		orientation;
}				t_playerPos;

typedef struct s_playerInfo
{
	t_playerPos	*pos;
}				t_playerInfo;

typedef struct s_dda
{
	bool		hit;
	int			hitside;
	double		perpendiculardist;
	double		wallx;
}				t_dda;

typedef struct s_lines {
	int			y;
	t_ivector	texture;
	double		step;
	double		texturepos;
	unsigned int color;
}				t_lines;

typedef struct s_ray
{
	int			screen_pixel;
	t_vector	camera;
	t_vector	raydir;
	t_vector	deltadist;
	t_vector	mappos;
	t_vector	distto;
	t_vector	step;
	double		walllinesize;
	int			walllinesizeint;
	int			linestart;
	int			lineend;
	t_vector	velocity;
	int			speed;
	t_dda		dda;
	t_lines		line;
}				t_ray;

typedef struct s_texture
{
	void			*n;
	void			*we;
	void			*so;
	void			*ea;
	unsigned int	*naddr;		// Endereço da imagem
	unsigned int	*waddr;		// Endereço da imagem
	unsigned int	*saddr;
	unsigned int	*eaddr;
	int				nbitspixel;	// Bits por pixel
	int				wbitspixel;	// Bits por pixel
	int				sbitspixel;
	int				ebitspixel;
	int				nlinelen;		// Tamanho da linha da imagem em bytes
	int				wlinelen;		// Tamanho da linha da imagem em bytes
	int				slinelen;
	int				elinelen;
	int				nendian;
	int				wendian;
	int				sendian;
	int				eendian;
}				t_texture;

typedef struct s_game
{
	t_map		map;		//? Estrutura com as informações do mapa
	t_data		data;		//? Estrutura com as informações para a mlx
	t_ray		ray;		//? Estrutura com as informações para o raycasting
	t_playerPos	pos;		//? Estrutura com as informações do jogador
	t_texture	texture;
}				t_game;

void		init_struct2(t_game *game);
void		init_struct(t_game *game);
void		get_xpm(t_game *game);
void		init_game(t_game *game);
int			key_press(int kc, t_game *game);
int			esc_key(t_game *game);
void		map_validations(t_game *game);
void		get_map_y(t_game *game);
void		get_map_x(t_game *game);
void		check_walls(t_game *game);
bool		flood(t_game *game, int start);
bool		verify_flood(char **map);
bool		flood_walls(t_game *game, char **map, int col, int row);
void		alloc_map(t_game *game);
int			get_min(int a, int b);
int			get_len_line(t_game *game, char **map, int y, t_len_line *len_info);
bool		verify_long_lines(t_game *game, char **map);
bool		check_middle_lines(t_game *game, char **map);
bool		first_last_lines(char *line);
void		init_len_info(t_len_line *leninfo);
t_playerPos	get_position(t_game *game, char **map);
void		set_direction(t_game *game, t_playerPos position);
bool		is_valid_char(char c);
void		get_direction(t_map	*map, double dir_x, double dir_y);
void		get_plane(t_map	*map, double plane_x, double plane_y);
int			loop(t_game *game);
void		assign_vector_values(t_vector *vector, double y, double x);
void		init_game(t_game *game);
void		dda(t_game *game);
void		map_validations(t_game *game);
void		set_direction(t_game *game, t_playerPos position);
void		algoritm_dda(t_game *game);
void		distance_step_side(t_game *game);
void		init_game(t_game *game);
void		get_texture_info(t_game *game);
void		error(t_game *game, char *msg);
void		assign_ivector_values(t_ivector *vector, int y, int x);
void		read_map_area(t_game *game);
void		get_area_x(t_game *game);
void		get_area_y(t_game *game);
void		floor_colors(t_game *game);
void		ceiling_colors(t_game *game);
void		map_info(t_game *game);
void		get_mapa_x(t_game *game);
void		print_map(t_game *game);
void		check_textures(t_game *game);
bool		is_valid_char(char c);
bool		verify_around_spaces(t_game *game, char **map);
bool		is_not_texture(char *line);
void		parse_textures(t_game *game, char *line,
				bool *ceiling, bool *floor);
void		verify_textures(bool ceiling, bool floor, t_game *game);
void		moviment_key(t_game *game, double new_x, double new_y);
void		direction_key(t_game *game, double val);
void		draw_line(t_game *game);
void		free_exit(t_game *game);
int			encode_rgb(uint8_t r, uint8_t g, uint8_t b);

#endif