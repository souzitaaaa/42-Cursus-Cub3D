#include "../includes/cub3d.h"

void	distance_step_side(t_game *game)
{
	int		i = 0;

	if (game->ray.ray_dir_x[i] < 0)
	{
		game->ray.step_x = -1;
		game->ray.side_dist_x = (game->ray.ray_x - game->ray.ray_pos_x[i]) * game->ray.delta_dist_x;
	}
	else
	{
		game->ray.step_x = 1;
		game->ray.side_dist_x = (game->ray.ray_pos_x[i] + 1.0 - game->ray.ray_x) * game->ray.delta_dist_x;
	}
	if (game->ray.ray_dir_y[i] < 0)
	{
		game->ray.step_y = -1;
		game->ray.side_dist_y = (game->ray.ray_y - game->ray.ray_pos_y[i]) * game->ray.delta_dist_y;
	}
	else
	{
		game->ray.step_y = 1;
		game->ray.side_dist_y = (game->ray.ray_pos_y[i] + 1.0 - game->ray.ray_y) * game->ray.delta_dist_y;
	}
	printf("lado x: %f  lado y: %f\n", game->ray.side_dist_x, game->ray.side_dist_y);
}

void	algoritm_dda(t_game *game)
{
	int hit = 0;

	while (!hit)
	{
	if (game->ray.side_dist_x < game->ray.side_dist_y)
	{
		game->ray.side_dist_x += game->ray.delta_dist_x;
		game->ray.ray_x += game->ray.step_x;
		game->ray.side = 0;
	}
	else
	{
		game->ray.side_dist_y += game->ray.delta_dist_y;
		game->ray.ray_y += game->ray.step_y;
		game->ray.side = 1;
	}
	if (game->map.area[(int)game->ray.ray_x][(int)game->ray.ray_y] == '1')
		hit = 1;
	}
}
