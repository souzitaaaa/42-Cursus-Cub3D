#include "./includes/cub3d.h"
#include "./minilibx-linux/mlx.h"

void init_struct(t_game *game)
{
	game->map.map_y = 0;
	game->map.map_x = 0;
	game->ray.screen_x = 0;
	game->ray.map_x = 0;
	game->ray.map_y = 0;
	//! estás a iniciar valores com o map_x e map_y que ainda não foram atribuidos
	return;
}

//* Esta função está a correr com a janela, e vai atribuindo os valores necessários para num futuro
//*		puderem ser utilizados para realizar o raycasting
int loop(t_game *game)
{
	double cameraX = 0;
	while(game->ray.screen_x < SCREEN_X)
	{
		cameraX = 2 * game->ray.screen_x / (double)SCREEN_X - 1;
		game->ray.ray_dir_x_2 = game->map.dir_x + game->map.plane_x * cameraX;
		game->ray.ray_dir_y_2 = game->map.dir_y + game->map.plane_y * cameraX;
		game->ray.screen_x++;
		game->ray.map_x = game->pos.row;
		game->ray.map_y = game->pos.col;
		//? Como se calcula o valor inicial do sideDist, ou não é preciso?
		//? É porque ele só ensina o do deltaDist
		game->ray.delta_dist_x = fabs(1 / game->ray.ray_dir_x_2);
		game->ray.delta_dist_y = fabs(1 / game->ray.ray_dir_y_2);
		printf("---------------------------------------\n");
		printf("cameraX: %f\n", cameraX);
		printf("ray_dir_x: %f\n", game->ray.ray_dir_x_2);
		printf("ray_dir_y: %f\n", game->ray.ray_dir_y_2);
		printf("screen_x: %f\n", game->ray.screen_x);
		printf("map_x: %d\n", game->ray.map_x);
		printf("map_y: %d\n", game->ray.map_y);
		printf("delta_dist_x: %f\n", game->ray.delta_dist_x);
		printf("delta_dist_y: %f\n", game->ray.delta_dist_y);
		printf("---------------------------------------\n");
	}
	return 1;
}

void init_game_teste(t_game *game)
{
	game->data.mlx = mlx_init();
	game->data.win = mlx_new_window(game->data.mlx, SCREEN_X, SCREEN_Y, "cub3D");
	mlx_loop_hook(game->data.mlx, loop, game);
	mlx_loop(game->data.mlx);
}

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
	game.ray.ray_dir_x = malloc(game.map.map_x * sizeof(double));
	game.ray.ray_dir_y = malloc(game.map.map_y * sizeof(double));
	game.ray.ray_pos_x = malloc(game.map.map_x * sizeof(double));
	game.ray.ray_pos_y = malloc(game.map.map_y * sizeof(double));
	printf("Posição do jogador: linha %d, coluna %d, orientation %c\n", player.row, player.col, player.orientation);
	set_direction(&game, player);
	game.pos = player;
	printf("dir_x: %d, dir_y: %d, plane_x: %d, plane_y: %d\n", game.map.dir_x, game.map.dir_y, game.map.plane_x, game.map.plane_y);
	//calculate_rays(&game);
	init_game_teste(&game);
}