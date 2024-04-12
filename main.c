#include "./includes/cub3d.h"
#include "./minilibx-linux/mlx.h"

/**
 * @brief 		Function used to initializate the some data on the main struct
 * 			so it doesn't happen any error, during assignments
 *
 * @param game	Struct that contains every information on the program
 */
void init_struct(t_game *game)
{
	game->map.mapa_y = 0;
	game->map.mapa_x = 0;
	game->ray.screen_pixel = 0;
	assign_vector_values(&game->ray.distTo, 0, 0);
	assign_vector_values(&game->ray.step, 0, 0);
	assign_vector_values(&game->ray.velocity, 0, 0);
	game->key.new_x = 0;
	game->key.new_y = 0;
	return;
}

void get_xpm(t_game *game) {
	int tile_size = 32;
	game->texture.N = mlx_xpm_file_to_image(game->data.mlx, TESTE,
			&tile_size, &tile_size);
	game->texture.N_addr = (unsigned int *)mlx_get_data_addr(game->texture.N, &game->texture.N_bitsPixel, &game->texture.N_lineLen, &game->texture.N_endian);
	game->texture.WE = mlx_xpm_file_to_image(game->data.mlx, TESTE2,
			&tile_size, &tile_size);
	game->texture.W_addr = (unsigned int *)mlx_get_data_addr(game->texture.WE, &game->texture.W_bitsPixel, &game->texture.W_lineLen, &game->texture.W_endian);
}

int key_press(int kc, t_game *game) {
	if (kc == 65307)
		esc_key(game);
	if (kc == 119)
		moviment_key(game, game->pos.row + game->map.dir.x * MOVESTEP, game->pos.col + game->map.dir.y * MOVESTEP);
	if (kc == 97)
		moviment_key(game, game->pos.row + game->map.dir.y * MOVESTEP, game->pos.col - game->map.dir.x * MOVESTEP);
	if (kc == 115)
		moviment_key(game, game->pos.row - game->map.dir.x * MOVESTEP, game->pos.col - game->map.dir.y * MOVESTEP);
	if (kc == 100)
		moviment_key(game, game->pos.row - game->map.dir.y * MOVESTEP, game->pos.col + game->map.dir.x * MOVESTEP);
	if (kc == 65363)
		direction_key(game, -0.2);
	if (kc == 65361)
		direction_key(game, 0.2);
	return (1);
}

/**
 * @brief 		Function to init the instances of the mlx library, such as
 * 			the mlx instance, the window, image and loops
 *
 * @param game	Struct that contains every information on the program
 */
void init_game_teste(t_game *game)
{
	game->data.mlx = mlx_init();
	game->data.win = mlx_new_window(game->data.mlx, SCREEN_X, SCREEN_Y, "cub3D");
	game->data.img = mlx_new_image(game->data.mlx, SCREEN_X, SCREEN_Y);
	game->data.addr = (unsigned int *)mlx_get_data_addr(game->data.img, &game->data.bits_per_pixel, &game->data.line_len, &game->data.endian);
	get_xpm(game);
	mlx_loop_hook(game->data.mlx, loop, game);
	mlx_hook(game->data.win, 2, 1L << 0, key_press, game);
	mlx_hook(game->data.win, 17, 0, esc_key, game);
	mlx_loop(game->data.mlx);
}
/**
 * @brief		Main function of the program, from here we decide the flow,
 * 			of the program, deciding how to deal with our information
 *
 * @param ac	Integer type variable that contains the number of arguments
 * @param av	Array containing the arguments, by order of insertion
 * @return int	Main function return a integer
 */
int	main(int ac, char **av)
{
	t_game	game;
	t_playerPos	player;

	if (ac != 2)
		error(&game, "Wrong number of arguments");
	if (av[1] == NULL)
	{
		printf("Error\n No map inserted");
		exit (EXIT_FAILURE);
	}
	game.map.map_folder = av[1];
	game.map.no_texture = NULL;
	game.map.so_texture = NULL;
	game.map.we_texture = NULL;
	game.map.ea_texture = NULL;
	//printf("Map folder: %s\n", game.map.map_folder);
	init_struct(&game);
	map_validations(&game);
	player = get_position(&game, game.map.map_a);
	game.pos = player;
	//printf("Player Info | col(y): %f | row(x): %f | orientation: %c |\n", game.pos.col, game.pos.row, game.pos.orientation);
	set_direction(&game, player);
	//printf("Dir vector  | col(y): %i | row(x): %i |\n", (int)game.map.dir.y, (int)game.map.dir.x);
	//printf("Plane vector| col(y): %i | row(x): %i |\n", (int)game.map.plane.y, (int)game.map.plane.x);
	game.pos.col += 0.5;
	game.pos.row += 0.5;
	init_game_teste(&game);
}