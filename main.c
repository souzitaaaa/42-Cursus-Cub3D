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
	game->key.minimap = false;
	game->ray.speed = 5;
	game->ray.rendered = false;
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

void get_pixel(t_game *game) {
	unsigned int a = mlx_get_color_value(game->data.mlx, COLOR2);
	printf("N_bitsPixel: %i\n", game->texture.N_bitsPixel);
	printf("N_lineLen: %i\n", game->texture.N_lineLen);
	printf("N_endian: %i\n", game->texture.N_endian);
	printf("a: %i\n", a);
}

int key_press(int kc, t_game *game) {
	(void)game;
	if (kc == 65307) {
		printf("Thanks for playing :P\n");
		exit(1);
	}
	if (kc == 109) {
		printf("|\tM\t|\n");
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->texture.N, 0 * 64, 0 * 64);
		mlx_put_image_to_window(game->data.mlx, game->data.win,
			game->texture.WE, 1 * 64, 0 * 64);
		printf("%i\n", mlx_get_color_value(game->data.mlx, COLOR1));
		//game->data.addr[1] = 0x000155ac;
		//mlx_put_image_to_window(game->data.mlx, game->data.win, game->data.img, 0, 0);
	}
	if (kc == 119) {
		printf("|\tW\t|\n");
		printf("value y: %i\n", (int)(game->pos.col + game->map.dir.y * 0.2));
		printf("value x: %i\n", (int)game->pos.row);
		printf("on arr: %c\n", game->map.map_a[(int)(game->pos.col + game->map.dir.y * 0.2)][(int)game->pos.row]);
		// if (game->map.map_a[(int)(game->pos.col + game->map.dir.y * 0.2)][(int)game->pos.row] != '1')
		// {
		// 	printf("entrou w\n");
		// 	printf("antes pos col: %f\n", game->pos.col);
		// 	printf("dir y: %f\n", game->map.dir.y);
		// 	game->pos.col += game->map.dir.y * 0.2;
		// 	printf("depois pos col: %f\n", game->pos.col);
		// 	game->ray.screen_pixel = 0;
		// 	//draw_ceiling_walls(game);
		// 	game->ray.rendered = false;
		// }
		double move_step = 0.1;
    	double new_x = game->pos.row + game->map.dir.x * move_step;
    	double new_y = game->pos.col + game->map.dir.y * move_step;
    	if (game->map.map_a[(int)new_y][(int)new_x] != '1') {
        	game->pos.row = new_x;
        	game->pos.col = new_y;
        	game->ray.screen_pixel = 0;
       		game->ray.rendered = false;
    	}
	}
	if (kc == 97) {
		printf("|\tA\t|\n");
		printf("value y: %i\n", (int)game->pos.col);
		printf("value x: %i\n", (int)(game->pos.row - game->map.dir.x * 0.2));
		printf("on arr: %c\n", game->map.map_a[(int)(game->pos.col + game->map.dir.y * 0.2)][(int)game->pos.row]);
		// if (game->map.map_a[(int)game->pos.col][(int)(game->pos.row + game->map.dir.y * 0.2)]  != '1')
		// {
		// 	printf("entrou a\n");
		// 	printf("antes pos row: %f\n", game->pos.row);
		// 	printf("dir y: %f\n", game->map.dir.y);
		// 	game->pos.row += game->map.dir.y * 0.2;
		// 	printf("before pos row: %f\n", game->pos.row);
		// 	game->ray.screen_pixel = 0;
		// 	//draw_ceiling_walls(game);
		// 	game->ray.rendered = false;
		// }
		double move_step = 0.1;
    	double new_x = game->pos.row + game->map.dir.y * move_step;
    	double new_y = game->pos.col - game->map.dir.x * move_step;
    	if (game->map.map_a[(int)new_y][(int)new_x] != '1') {
        	game->pos.row = new_x;
        	game->pos.col = new_y;
        	game->ray.screen_pixel = 0;
        	game->ray.rendered = false;
    	}
	}
	if (kc == 115) {
		printf("|\tS\t|\n");
		printf("value y: %i\n", (int)(game->pos.col - game->map.dir.y * 0.2));
		printf("value x: %i\n", (int)game->pos.row);
		printf("on arr: %c\n", game->map.map_a[(int)(game->pos.col - game->map.dir.y * 1)][(int)game->pos.row]);
		// if (game->map.map_a[(int)(game->pos.col - game->map.dir.y * 0.2)][(int)game->pos.row] != '1')
		// {
		// 	printf("entrou s\n");
		// 	printf("antes pos col: %f\n", game->pos.col);
		// 	printf("dir y: %f\n", game->map.dir.y);
		// 	game->pos.col -= game->map.dir.y * 0.2;
		// 	printf("depois pos col: %f\n", game->pos.col);
		// 	game->ray.screen_pixel = 0;
		// 	//draw_ceiling_walls(game);
		// 	game->ray.rendered = false;
		// }
		double move_step = 0.1; // Adjust this value according to your needs
    	double new_x = game->pos.row - game->map.dir.x * move_step;
    	double new_y = game->pos.col - game->map.dir.y * move_step;
    	if (game->map.map_a[(int)new_y][(int)new_x] != '1') {
        	game->pos.row = new_x;
        	game->pos.col = new_y;
        	game->ray.screen_pixel = 0;
        	game->ray.rendered = false;
    	}
	}
	if (kc == 100) {
		printf("|\tD\t|\n");
		printf("value y: %i\n", (int)game->pos.col);
		printf("value x: %i\n", (int)(game->pos.row + game->map.dir.x * 0.2));
		printf("on arr: %c\n", game->map.map_a[(int)(game->pos.col - game->map.dir.y * 1)][(int)game->pos.row]);
		// if (game->map.map_a[(int)game->pos.col][(int)(game->pos.row - game->map.dir.y * 0.2)]  != '1')
		// {
		// 	printf("entrou d\n");
		// 	printf("antes pos row: %f\n", game->pos.row);
		// 	printf("dir y: %f\n", game->map.dir.y);
		// 	game->pos.row -= game->map.dir.y * 0.2;
		// 	printf("before pos row: %f\n", game->pos.row);
		// 	game->ray.screen_pixel = 0;
		// 	//draw_ceiling_walls(game);
		// 	game->ray.rendered = false;
		// }
		double move_step = 0.1; // Adjust this value according to your needs
    	double new_x = game->pos.row - game->map.dir.y * move_step;
    	double new_y = game->pos.col + game->map.dir.x * move_step;
    	if (game->map.map_a[(int)new_y][(int)new_x] != '1') {
        	game->pos.row = new_x;
        	game->pos.col = new_y;
        	game->ray.screen_pixel = 0;
        	game->ray.rendered = false;
    	}
	}
	if (kc == 65363) {
		printf("|\tR\t|\n");
		t_vector	oldDir;
		t_vector	oldPlane;

		assign_vector_values(&oldDir, game->map.dir.y, game->map.dir.x);
		printf("oldDir  | y:  %f  |  x: %f  |\n", oldDir.y, oldDir.x);
		printf("dir     | y:  %f  |  x: %f  |\n", game->map.dir.y, game->map.dir.x);
		game->map.dir.y = game->map.dir.y * cos(-0.2) - game->map.dir.x * sin(-0.2);
		game->map.dir.x = oldDir.y * sin(-0.2) + game->map.dir.x * cos(-0.2);
		printf("dir     | y:  %f  |  x: %f  |\n", game->map.dir.y, game->map.dir.x);
		assign_vector_values(&oldPlane, game->map.plane.y, game->map.plane.x);
		printf("oldPlane| y:  %f  |  x: %f  |\n", oldPlane.y, oldPlane.x);
		printf("Plane   | y:  %f  |  x: %f  |\n", game->map.plane.y, game->map.plane.x);
		game->map.plane.y = game->map.plane.y * cos(-0.2) - game->map.plane.x * sin(-0.2);
		game->map.plane.x = oldPlane.y * sin(-0.2) + game->map.plane.x * cos(-0.2);
		printf("Plane   | y:  %f  |  x: %f  |\n", game->map.plane.y, game->map.plane.x);
		game->ray.screen_pixel = 0;
		//draw_ceiling_walls(game);
		game->ray.rendered = false;
	}
	if (kc == 65361) {
		printf("|\tL\t|\n");
		t_vector	oldDir;
		t_vector	oldPlane;

		assign_vector_values(&oldDir, game->map.dir.y, game->map.dir.x);
		printf("oldDir| y:  %f  |  x: %f  |\n", oldDir.y, oldDir.x);
		printf("dir     | y:  %f  |  x: %f  |\n", game->map.dir.y, game->map.dir.x);
		game->map.dir.y = game->map.dir.y * cos(0.2) - game->map.dir.x * sin(0.2);
		game->map.dir.x = oldDir.y * sin(0.2) + game->map.dir.x * cos(0.2);
		printf("dir     | y:  %f  |  x: %f  |\n", game->map.dir.y, game->map.dir.x);
		assign_vector_values(&oldPlane, game->map.plane.y, game->map.plane.x);
		printf("oldPlane| y:  %f  |  x: %f  |\n", oldPlane.y, oldPlane.x);
		printf("Plane   | y:  %f  |  x: %f  |\n", game->map.plane.y, game->map.plane.x);
		game->map.plane.y = game->map.plane.y * cos(0.2) - game->map.plane.x * sin(0.2);
		game->map.plane.x = oldPlane.y * sin(0.2) + game->map.plane.x * cos(0.2);
		game->ray.screen_pixel = 0;
		//draw_ceiling_walls(game);
		game->ray.rendered = false;
	}
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
	get_pixel(game);
	mlx_loop_hook(game->data.mlx, loop, game);
	mlx_hook(game->data.win, 2, 1L << 0, key_press, game);
	//draw_ceiling_walls(game);
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
	game.map.no_texture = NULL;
	game.map.so_texture = NULL;
	game.map.we_texture = NULL;
	game.map.ea_texture = NULL;
	printf("Map folder: %s\n", game.map.map_folder);
	init_struct(&game);
	map_validations(&game);
	player = get_position(&game, game.map.map_a);
	game.pos = player;
	printf("Player Info | col(y): %f | row(x): %f | orientation: %c |\n", game.pos.col, game.pos.row, game.pos.orientation);
	set_direction(&game, player);
	printf("Dir vector  | col(y): %i | row(x): %i |\n", (int)game.map.dir.y, (int)game.map.dir.x);
	printf("Plane vector| col(y): %i | row(x): %i |\n", (int)game.map.plane.y, (int)game.map.plane.x);
	//usleep(9999999);
	game.pos.col += 0.5;
	game.pos.row += 0.5;
	init_game_teste(&game);
}