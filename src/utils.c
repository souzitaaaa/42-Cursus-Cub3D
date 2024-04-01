#include "../includes/cub3d.h"

void	my_mlx_pixel_put(t_game *game, int x, int y, int color)
{
	unsigned int	*dst;

	dst = game->data.addr + (y * game->data.line_len + x * (game->data.bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	draw_ceiling_walls(t_game *game)
{
	int	x = 0;
	int	y = 0;

	while (y < SCREEN_Y / 2)
	{
		x = 0;
		while (x < SCREEN_X)
		{
			my_mlx_pixel_put(game, x, y, CEILING_COLOR);
			x++;
		}
		y++;
	}
	y = SCREEN_Y / 2;
	while (y < SCREEN_Y)
	{
		x = 0;
		while (x < SCREEN_X)
		{
			my_mlx_pixel_put(game, x, y, FLOOR_COLOR);
			x++;
		}
		y++;
	}
	return (0);
}

