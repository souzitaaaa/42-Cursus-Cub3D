#include "../includes/cub3d.h"

void alloc_map(t_game *game)
{
	int i;
	char *out;

	i = 0;
	game->map.fd = open(game->map.map_folder, O_RDONLY);
	game->map.area = (char **)malloc(sizeof(char *) * (game->map.map_y + 1));
	if (!game->map.area) {
		//! FREE?
		exit(EXIT_FAILURE);
	}
	while (i < game->map.map_y + 1) {
		out = get_next_line(game->map.fd);
		game->map.area[i] = ft_strtrim(out, "\n");
		free(out);
		i++;
	}
	close(game->map.fd);
	printf("Map: \n");
	print_arr(game->map.area);
	//! VAI TER QUE SE DAR FREE DA GAME->MAP.AREA
}

bool flood_walls(t_game *game, char **map, int col, int row)
{
	if (col < 0 || row < 0 || col >= game->map.map_y || row >= game->map.map_x)
		return false;
	else if (map[col][row] != '1')
		return false;
	else if (map[col][row] == 'X')
		return false;
	map[col][row] = 'X';
	flood_walls(game, map, col + 1, row);
	flood_walls(game, map, col, row + 1);
	flood_walls(game, map, col + 1, row + 1);
	flood_walls(game, map, col - 1, row + 1);
	flood_walls(game, map, col - 1, row);
	flood_walls(game, map, col, row - 1);
	flood_walls(game, map, col - 1, row - 1);
	flood_walls(game, map, col + 1, row - 1);
	return true;
}

bool verify_flood(char **map)
{
	int row = 0;
	int col = 0;
	int row_back = 0;
	while (map[col])
	{
		row = 0;
		row_back = 0;
		while (map[col][row])
		{
			while(map[col][row] == ' ')
				row++;
			if (map[col][row] != 'X')
				return true;
			else
				break;
		}
		row_back = ft_strlen(map[col]) - 1;
		while (map[col][row_back])
		{
			while(map[col][row_back] == ' ')
				row_back--;
			if (map[col][row_back] != 'X')
				return true;
			else
				break;
		}
		col++;
	}
	return false;
}

bool flood(t_game *game, int start)
{
	char **map;
	bool valid;

	map = ft_arrdup(game->map.area);
	valid = flood_walls(game, map, start, 0);
	printf("Map flood walls: \n");
	valid = verify_flood(map);
	print_arr(map);
	ft_free_array(&map);
	return (valid);
}

void check_walls(t_game *game)
{
	int start;

	start = 0;
	while (game->map.area[start][0] != '1')
		start++;
	if (flood(game, start)) {
		printf("Error\n The map isn't surrounded by walls\n");
		//! FREE
		exit(EXIT_FAILURE);
	}
}

void get_map_x(t_game *game)
{
	int i;
	int len;
	int x;

	i = 1;
	x = ft_strlen(game->map.area[0]);
	len = 0;
	while (i < game->map.map_y) {
		len = ft_strlen(game->map.area[i]);
		if (len > x)
			x = len;
		i++;
	}
	game->map.map_x = x;
	printf("Map col(y): %i\n", game->map.map_y);
	printf("Map row(x): %i\n", game->map.map_x);
}

void get_map_y(t_game *game)
{
    int y;
	char *out;

	game->map.fd = open(game->map.map_folder, O_RDONLY);
	y = 0;
	while (1) {
		out = get_next_line(game->map.fd);
		if (!out)
			break;
		y++;
		free(out);
	}
	if (y == 0) {
		printf("Erro\nFicheiro vazio!\n"); 
		exit(EXIT_FAILURE);
	}
	game->map.map_y = y;
	close(game->map.fd);
}

void map_validations(t_game *game)
{
	int pos;

	pos = strlen(game->map.map_folder) - 4;
	if (strncmp(".cub", &game->map.map_folder[pos], 4) != 0)
	{
		printf("Error\n The map you provided isn't .cub\n");
		exit (EXIT_FAILURE);
	}
    get_map_y(game);
	alloc_map(game);
	get_map_x(game);
	check_walls(game);
}
