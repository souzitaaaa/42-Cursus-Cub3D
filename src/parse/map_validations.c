#include "../includes/cub3d.h"

int	get_min(int	a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

bool	verify_long_lines(t_game *game, char **map)
{
	int	len_current_line;
	int	len_prev_line;
	int	len_next_line;
	int	x;
	int	y = 0;

	while (y < game->map.mapa_y)
	{
		len_current_line = ft_strlen(map[y]);
		if (y > 0)
			len_prev_line = ft_strlen(map[y - 1]);
		else
			len_prev_line = len_current_line;
		if (y < game->map.mapa_y - 1)
			len_next_line = ft_strlen(map[y + 1]);
		else
			len_next_line = len_current_line;
		if (len_prev_line < len_current_line || len_next_line < len_current_line)
		{

			x = get_min(len_prev_line, len_next_line);
			while (map[y][x] != '\0')
			{
				if (map[y][x] != '1')
					return (false);
				x++;
			}
		}
		y++;
	}
	return (true);
}

bool	check_middle_lines(t_game *game, char **map)
{
	int		i = 1;
	char	first_char;
	char	last_char;
	int		pos_last_char;

	while (i < game->map.mapa_y - 1)
	{
		pos_last_char = ft_strlen(map[i]) - 1;
		first_char = map[i][0];
		last_char = map[i][pos_last_char];
 		if ((first_char != '1' && first_char != ' ') || (last_char != '1' && last_char != ' '))
 			return (false);
		i++;
	}
	return (true);
}

bool	check_peripheral_lines(char *line)
{
	int x;

	x = 0;
	while (line[x] != '\0')
	{
		if (line[x] != '1' && line[x] != ' ')
			return (false);
		x++;
	}
	return (true);
}

bool	verify_walls(t_game *game)
{
	// Verifica a volta do mapa:
	//1º caracter e ultimo de todas as linhas tem que ser 1 ou espaço
	if (check_middle_lines(game, game->map.map_a) == false)
	 	return (false);
	if (check_peripheral_lines(game->map.map_a[0]) == false || check_peripheral_lines(game->map.map_a[game->map.mapa_y - 1]) == false)
	 	return (false);
	if (verify_around_spaces(game, game->map.map_a) == false)
		return (false);
	 if (verify_long_lines(game, game->map.map_a) == false)
	 	return (false);
	return(true);
}

void map_validations(t_game *game)
{
	int pos;

	pos = strlen(game->map.map_folder) - 4;
	if (ft_strncmp(".cub", &game->map.map_folder[pos], 4) != 0)
	{
		printf("Error\n The map you provided isn't .cub\n");
		exit (EXIT_FAILURE);
	}
	get_area_y(game);
	read_map_area(game);
	get_area_x(game);
	map_info(game);
	check_textures(game);
	get_mapa_x(game);
	if (verify_walls(game) == false)
	{
		ft_printf("Error\n The map has to be surrounded by walls.");
		exit(EXIT_FAILURE);
	}
}