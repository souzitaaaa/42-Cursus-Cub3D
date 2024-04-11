#include "../includes/cub3d.h"

void print_map(t_game *game) {
    int i;
	int	j;

    i = 0;
	while (i < game->map.mapa_y)
	{
		j = 0;
		while (j < game->map.mapa_x)
		{
			ft_printf("%d", game->map.map_a[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
	printf("\n");
}

bool	is_wall_or_space(char c)
{
	if (c == '1' || c == ' ')
		return (true);
	return (false);
}

bool verify_neighbors(t_game *game, char **map, int x, int y)
{
	if (x > 0 && is_wall_or_space(map[y][x - 1]) == false)
	{
			ft_printf("em cima\n");
			return (false);
	}
	if (x + 1 < game->map.mapa_x && is_wall_or_space(map[y][x + 1]) == false)
	{
		ft_printf("em baixo: x: %d | y: %d\n", game->map.mapa_x, game->map.mapa_y);
		return (false);
	}
	if (y > 0 && (int)ft_strlen(map[y - 1]) > x && is_wall_or_space(map[y - 1][x]) == false)
	{
		ft_printf("para esquerda\n");
		return (false);
	}
	if (y + 1 < game->map.mapa_y && (int)ft_strlen(map[y + 1]) > x && is_wall_or_space(map[y + 1][x]) == false)
	{
		ft_printf("para direita\n");
		return (false);
	}
	return (true);
}

bool verify_around_spaces(t_game *game, char **map)
{
	int	x;
	int	y;

	y = 0;
	while(y < game->map.mapa_y)
	{
		x = 0;
		//PERCORRER A LINHA SEMPRE ASSIM PQ PODE TER LIXOS NO MAPA
		while (map[y][x] != '\0')
		{
			if (map[y][x] == ' ')
			{
			 	if (verify_neighbors(game, map, x, y) == false)
		 			return (false);
			}
			x++;
		}
		y++;
	}
	return (true);
}