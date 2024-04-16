#ifndef CUB3D_H
# define CUB3D_H

# include "../libft/include/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
#include <stdint.h>
# include <string.h>
# include <math.h>

# define SCREEN_X 800
# define SCREEN_Y 400
# define FOV 60
# define MOVESTEP	0.1

# define YELLOW "\033[0;31m"
# define RESET "\033[0m"
# define COLOR1 0x000155ac
# define COLOR2 0x000c184e
# define COLOR3 0x00ffcc41
# define COLOR4 0x00ef8833
# define CEILING_COLOR 0x0094e3e4
# define FLOOR_COLOR 0x0033ac25

# define TEXTURE_X 64
# define TESTE "./textures/Tori-gate.xpm"
# define TESTE2	 "./textures/kingdom.xpm"

# if OS == 1
#  include "../minilibx-linux/mlx.h"
# 	define ESC 65307
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

//? col = y || row = x

typedef struct s_vector {
	double	x;
	double	y;
} 				t_vector;

typedef struct s_ivector {
	int		x;
	int		y;
} 				t_ivector;

typedef	struct	s_len_line {
	int		len_current_line;
	int		len_prev_line;
	int		len_next_line;
}					t_len_line;

typedef struct s_map
{
	char	*map_folder; 	//? Ficheiro do mapa
	char	*no_texture;	//? array textura NO
	char	*so_texture;	//? array textura SO
	char	*we_texture;	//? array textura WE
	char	*ea_texture;	//? array textura EA
	int		f_range[3];		//? range das cores p/ chao
	int		c_range[3];		//? range das cores p/ ceu
	int		fd;			 	//? Fd para usar quando se abre o mapa
	char	**area;      	//? Array com o mapa
	char	**map_a;		//?array com o mapa depois de tratar as texturas
	int		mapa_y;
	int		mapa_x;
	int		area_y;       	//? Colunas do mapa
	int		area_x;       	//? Linhas do mapa
	t_vector	dir;		//? Vetor com os valores da direção da câmara
	t_vector	plane;		//? Vetor com os valores da posição do plano
}				t_map;

typedef struct s_data
{
	void	*mlx;			//? Instância da mlx
	void	*win;			//? Janela da mlx
	void	*img;			// Imagem da mlx
	unsigned int		*addr;			// Endereço da imagem
	int		bits_per_pixel;	// Bits por pixel
	int		line_len;	// Tamanho da linha da imagem em bytes
	int		endian;			// Endian da imagem
	void	*mm_img;			// Imagem da mlx
	char	*mm_addr;			// Endereço da imagem
	int		mm_bits_per_pixel;	// Bits por pixel
	int		mm_line_len;	// Tamanho da linha da imagem em bytes
	int		mm_endian;			// Endian da imagem
}				t_data;

typedef	struct s_playerPos {
	double		row;			//? Linha (x) onde o jogador está posicionado
	double		col;			//? Coluna (y) onde o jogador está posicionado
	char	orientation;	//? Orientação do jogador (N, S, E, W)
} t_playerPos;

typedef struct s_dda {
	bool		hit;
	int			hitSide;
	double		perpendicularDist;
	double		wallX;
} t_dda;

typedef struct s_lines {
	int			y;
	t_ivector	texture;
	double		step;
	double		texturePos;
	unsigned int color;
} t_lines;

typedef struct s_ray {
	int			screen_pixel;	 	//? Index do x relativamente á tela
	t_vector	camera;				//? Vetor com os valores da camera (ajuda ao calculo do raydir)
	t_vector	rayDir;				//? Vetor com os valores da direção do raio
	t_vector	deltaDist;
	double		deltaDistX;			//? Distância base entre cada X
	double		deltaDistY;			//? Distância base entre cada Y
	t_vector	mapPos;				//? Vetor com as coordenadas do player no mapa
	t_vector	distTo;				//? Coordenadas de x e y do distTo
	t_vector	step;				//? Informação do step relativamente ao x e y
	double		wallLineSize;		//? Tamanho da linha da parede
	int			wallLineSizeInt;
	int			lineStart;
	int			lineEnd;
	t_vector	velocity;
	int			speed;
	t_dda		dda;
	t_lines		line;
} t_ray;

typedef struct s_texture {
	void		*N;
	unsigned int		*N_addr;			// Endereço da imagem
	int		N_bitsPixel;	// Bits por pixel
	int		N_lineLen;	// Tamanho da linha da imagem em bytes
	int		N_endian;
	void		*WE;
	unsigned int		*W_addr;			// Endereço da imagem
	int		W_bitsPixel;	// Bits por pixel
	int		W_lineLen;	// Tamanho da linha da imagem em bytes
	int		W_endian;
} t_texture;

typedef struct s_game
{
	t_map		map;		//? Estrutura com as informações do mapa
	t_data		data;		//? Estrutura com as informações para a mlx
	t_ray		ray;		//? Estrutura com as informações para o raycasting
	t_playerPos pos;		//? Estrutura com as informações do jogador
	t_texture	texture;
}				t_game;

//* [src/map_check.c]
void 		map_validations(t_game *game);
void 		get_map_y(t_game *game);
void 		get_map_x(t_game *game);
void 		check_walls(t_game *game);
bool 		flood(t_game *game, int start);
bool 		verify_flood(char **map);
bool 		flood_walls(t_game *game, char **map, int col, int row);
void 		alloc_map(t_game *game);

/*
 Utils map validations
*/
int			get_min(int a, int b);
int			get_len_line(t_game *game, char **map, int y, t_len_line *len_info);
bool		verify_long_lines(t_game *game, char **map);
bool		check_middle_lines(t_game *game, char **map);
bool		first_last_lines(char *line);


//* [src/position.c]
t_playerPos	get_position(t_game *game, char **map);
void		set_direction(t_game *game, t_playerPos position);

//* [src/algorithm/dda-1.c]

int 		loop(t_game *game);
void		assign_vector_values(t_vector *vector, double y, double x);
void		init_game(t_game *game);
void 		dda(t_game *game);
void		map_validations(t_game *game);
void		set_direction(t_game *game, t_playerPos position);
void		algoritm_dda(t_game *game);
void		distance_step_side(t_game *game);
void		init_game(t_game *game);
void		get_texture_info(t_game *game);
/*
Utils
*/
void		error(t_game *game, char *msg);
void		assign_ivector_values(t_ivector *vector, int y, int x);


/* Map */
void		read_map_area(t_game *game);
void		get_area_x(t_game *game);
void		get_area_y(t_game *game);

/*
Parse
*/
void		floor_colors(t_game *game);
void		ceiling_colors(t_game *game);
void		map_info(t_game *game);
void		get_mapa_x(t_game *game);
void		print_map(t_game *game);
void		check_textures(t_game *game);
bool		is_valid_char(char c);
bool		verify_around_spaces(t_game *game, char **map);
bool        is_not_texture(char *line);
void        parse_textures(t_game *game, char *line, bool *ceiling, bool *floor);
void   		verify_textures(bool ceiling, bool floor, t_game *game);
int			esc_key(t_game *game);
void 		moviment_key(t_game *game, double new_x, double new_y);
void 		direction_key(t_game *game, double val);
void		draw_line(t_game *game);
void		free_exit(t_game *game);

#endif