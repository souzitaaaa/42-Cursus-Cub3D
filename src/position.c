#include "../includes/cub3d.h"

/*Essa função e para saber a posição do jogador porque os calculos dos raios começam nessa posição*/
t_playerPos	get_position(t_map *map)
{
	t_playerPos	pos = {-1, -1, ' '};

	char	**area = map->area;
	int		rows = map->map_y;
	int		cols = map->map_x;
	int x = 0;
	int y;

	while (x < rows)
	{
		y = 0;
		while (y < cols)
		{
			if (area[x][y] == 'N' || area[x][y] == 'S' || area[x][y] == 'E' || area[x][y] == 'W')
			{
				pos.row = x;
				pos.col = y;
				pos.orientation = area[x][y];
				return (pos);
			}
			y++;
		}
		x++;
	}
	return (pos);
}

/*Essa função é para setar a direção de visão do jogador levando em consideração a orientação, o plano
do jogador é ajustado para ser perpendicular à direção, ou seja, formando um plano horizontal que corta
a direção do jogador em um ângulo de 90 graus*/
void	set_direction(t_game *game, t_playerPos pos)
{
	t_map	*map = &(game->map);

	if (pos.orientation == 'N')
	{
		map->dir_x = 0;
		map->dir_y = -1;
		map->plane_x = 1;
		map->plane_y = 0;
	}
	else if (pos.orientation == 'S')
	{
		map->dir_x = 0;
		map->dir_y = 1;
		map->plane_x = -1;
		map->plane_y = 0;
	}
	else if (pos.orientation == 'W')
	{
		map->dir_x = -1;
		map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = -1;
	}
	else if (pos.orientation == 'E')
	{
		map->dir_x = 1;
		map->dir_y = 0;
		map->plane_x = 0;
		map->plane_y = 1;
	}
}
