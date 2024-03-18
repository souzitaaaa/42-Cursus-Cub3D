#include "../includes/cub3d.h"

bool	is_valid_char(char c)
{
	return (c == '0' || c == '1' || c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == ' ');
}

/*Essa função e para saber a posição do jogador, verifico se os caracteres validos do mapa e se tem mais de um jogador*/
t_playerPos	get_position(t_game *game, char **map)
{
	t_playerPos	pos = {-1, -1, ' '};
	int x;
	int y = 0;

	while (y < game->map.mapa_y)
	{
		x = 0;
		while (map[y][x] != '\0')
		{
			if (!is_valid_char(map[y][x]))
			{
				ft_printf("Error\n Invalid map character.\n");
				exit(EXIT_FAILURE);
			}
			if (map[y][x] == 'N' || map[y][x] == 'S' || map[y][x] == 'E' || map[y][x] == 'W')
			{
				if (pos.row != -1 || pos.col != -1)
				{
					ft_printf("Error\n It's not possible to have more than one player.\n");
					exit(EXIT_FAILURE);
				}
				pos.row = x;
				pos.col = y;
				pos.orientation = map[y][x];
			}
			x++;
		}
		y++;
	}
	if (pos.orientation == ' ')
	{
	 	ft_printf("Error\n The game must have one player.");
	 	exit(EXIT_FAILURE);
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
		map->dir.x = 0;
		map->dir.y = -1;
		map->plane.x = 1;
		map->plane.y = 0;
	}
	else if (pos.orientation == 'S')
	{
		map->dir.x = 0;
		map->dir.y = 1;
		map->plane.x = -1;
		map->plane.y = 0;
	}
	else if (pos.orientation == 'W')
	{
		map->dir.x = -1;
		map->dir.y = 0;
		map->plane.x = 0;
		map->plane.y = -1;
	}
	else if (pos.orientation == 'E')
	{
		map->dir.x = 1;
		map->dir.y = 0;
		map->plane.x = 0;
		map->plane.y = 1;
	}
}
