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
	game->map.map_y = 0;
	game->map.map_x = 0;
	game->ray.screen_pixel = 0;
	return;
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
	game->data.addr = mlx_get_data_addr(game->data.img, &game->data.bits_per_pixel, &game->data.line_len, &game->data.endian);
	mlx_loop_hook(game->data.mlx, loop, game);
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
	{
		printf("Error\n Wrong number of arguments\n");
		exit (EXIT_FAILURE);
	}
	if (av[1] == NULL)
	{
		printf("Error\n No map inserted");
		exit (EXIT_FAILURE);
	}
	game.map.map_folder = av[1];
	printf("Map folder: %s\n", game.map.map_folder);
	init_struct(&game);
	map_validations(&game);
	player = get_position(&(game.map));
	game.pos = player;
	printf("Player Info | col(y): %f | row(x): %f | orientation: %c |\n", game.pos.col, game.pos.row, game.pos.orientation);
	set_direction(&game, player);
	printf("Dir vector  | col(y): %i | row(x): %i |\n", (int)game.map.dir.y, (int)game.map.dir.x);
	printf("Plane vector| col(y): %i | row(x): %i |\n", (int)game.map.plane.y, (int)game.map.plane.x);
	game.pos.col += 0.5;
	game.pos.row += 0.5;
	init_game_teste(&game);
}