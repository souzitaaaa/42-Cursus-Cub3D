#include "./includes/cub3d.h"

void init_struct(t_game *game)
{
	game->map.map_y = 0;
	game->map.map_x = 0;
	game->map.ray_dir_x = malloc(game->map.map_x * sizeof(double));
	game->map.ray_dir_y = malloc(game->map.map_y * sizeof(double));
	game->map.ray_pos_x = malloc(game->map.map_x * sizeof(double));
	game->map.ray_pos_y = malloc(game->map.map_y * sizeof(double));
	game->map.ray_x = malloc(game->map.map_x * sizeof(int));
	game->map.ray_y = malloc(game->map.map_y * sizeof(int));
	game->map.side = malloc(game->map.map_x * sizeof(int));
	return;
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	get_code(int keycode, t_vars *vars)
{
	(void)vars;
	printf("Keycode of %c is %d\n",(char)keycode, keycode);
	//This will print the keycode of the ke pressed, it will be usefull to set up the keycodes on the enum struct
	return (0);
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
	printf("Posição do jogador: linha %d, coluna %d, orientation %c\n", player.row, player.col, player.orientation);
	set_direction(&game, player);
	printf("dir_x: %d, dir_y: %d, plane_x: %d, plane_y: %d\n", game.map.dir_x, game.map.dir_y, game.map.plane_x, game.map.plane_y);
	calculate_rays(&game);
}