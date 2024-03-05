#include "../includes/cub3d.h"

void	calculate_rays(t_game *game)
{
	(void)game;
	/*double	camera_x;
	int		i = 0;

	while (i < SCREEN_X)
	{
		camera_x = 2 * i / (double)SCREEN_X - 1;
		game->ray.ray_dir_x[i] = game->map.dir.x + game->map.plane.x * camera_x;
		game->ray.ray_dir_y[i] = game->map.dir.y + game->map.plane.y * camera_x;
		printf("Raio para coluna %d: (%f, %f)\n", i, game->ray.ray_dir_x[i], game->ray.ray_dir_y[i]);
		i++;
	}*/
}


// void	render_rays(t_game *game)
// {
// 	int	i = 0;
// 	double	ray_dir_x;
// 	double	ray_dir_y;

// 	calculate_rays(game);
// 	while(i < SCREEN_X)
// 	{
// 		ray_dir_x = game->map.ray_dir_x[i];
// 		ray_dir_y = game->map.ray_dir_y[i];
// 		i++;
// 	}
// }
