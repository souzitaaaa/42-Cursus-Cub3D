#include "../includes/cub3d.h"

void	calculate_rays(t_game *game)
{
	double	camera_x;
	int		i = 0;

	while (i < SCREEN_X)
	{
		camera_x = 2 * i / (double)SCREEN_X - 1;
		game->map.ray_dir_x[i] = game->map.dir_x + game->map.plane_x * camera_x;
		game->map.ray_dir_y[i] = game->map.dir_y + game->map.plane_y * camera_x;
		game->map.delta_x = fabs(1 / game->map.ray_dir_x[i]);
		game->map.delta_y = fabs(1 / game->map.ray_dir_y[i]);
		//printf("Raio para coluna %d: (%f, %f), Delta_X: %f, Delta_Y: %f\n", i, game->map.ray_dir_x[i], game->map.ray_dir_y[i], game->map.delta_x, game->map.delta_y);
		i++;
	}
}

