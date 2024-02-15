#include "./includes/cub3d.h"

void init_struct(t_game *game)
{
	(void)*game;
	return;
}

void map_validations(t_game *game)
{
	//* Checking the map extension
	int pos;

	pos = strlen(game->map.map_folder) - 4;
	if (strncmp(".cub", &game->map.map_folder[pos], 4) != 0)
	{
		printf("Error\n The map you provided isn't .cub\n");
		exit (EXIT_FAILURE);
	}
	//* End

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
	init_struct(&game);
	map_validations(&game);
}