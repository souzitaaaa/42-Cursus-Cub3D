#include "../../includes/cub3d.h"

/* Aloca memoria para a area(texturas, cores e mapa) e guarda em game->map.area */
void	read_map_area(t_game *game)
{
	int i;
	char *out;

	i = 0;
	game->map.fd = open(game->map.map_folder, O_RDONLY);
	game->map.area = ft_calloc(game->map.area_y + 1, sizeof(char *));
	if (!game->map.area) {
		//! FREE?
		exit(EXIT_FAILURE);
	}
	while (i < game->map.area_y + 1) {
		out = get_next_line(game->map.fd);
		game->map.area[i] = ft_strtrim(out, "\n");
		free(out);
		i++;
	}
	close(game->map.fd);
	// printf("Map: \n");
	// print_arr(game->map.area);
	//! VAI TER QUE SE DAR FREE DA GAME->MAP.AREA
}

/* pega o tamanho da linha de game->map.area e guarda em map_x*/
void	get_area_x(t_game *game)
{
	int i;
	int len;
	int x;

	i = 1;
	x = ft_strlen(game->map.area[0]);
	len = 0;
	while (i < game->map.area_y) {
		len = ft_strlen(game->map.area[i]);
		if (len > x)
			x = len;
		i++;
	}
	game->map.area_x = x;
}

/* pega o tamanho de game->map.area e guarda em area_y*/
void	get_area_y(t_game *game)
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
		printf("Error\nEmpty file!\n"); 
		exit(EXIT_FAILURE);
	}
	game->map.area_y = y;
	close(game->map.fd);
}

void	parse_textures(t_game *game, char *line)
{
	if (line[0] != '\0')
	{
		if (ft_strncmp(line, "NO ", 3) == 0)
		{
			if (game->map.no_texture)
			{
				ft_printf("Error\nDuplicate texture");
				exit(EXIT_FAILURE);
			}
			game->map.no_texture = ft_strdup(line + 3);
		}
		else if (ft_strncmp(line, "SO ", 3) == 0)
		{
			if (game->map.so_texture)
			{
				ft_printf("Error\nDuplicate texture");
				exit(EXIT_FAILURE);
			}
			game->map.so_texture = ft_strdup(line + 3);
		}
		else if (ft_strncmp(line, "WE ", 3) == 0)
		{
			if (game->map.we_texture)
			{
				ft_printf("Error\nDuplicate texture");
				exit(EXIT_FAILURE);
			}
			game->map.we_texture = ft_strdup(line + 3);
		}
		else if (ft_strncmp(line, "EA ", 3) == 0)
		{
			if (game->map.ea_texture)
			{
				ft_printf("Error\nDuplicate texture");
				exit(EXIT_FAILURE);
			}
			game->map.ea_texture = ft_strdup(line + 3);
		}
		else if (ft_strncmp(line, "F ", 2) == 0)
			floor_colors(game);
		else if (ft_strncmp(line, "C ", 2) == 0)
			ceiling_colors(game);
	}
}

bool	is_beg_map(char *line)
{
	if (ft_strncmp(line, "NO ", 3) != 0 &&
		ft_strncmp(line, "SO ", 3) != 0 &&
		ft_strncmp(line, "WE ", 3) != 0 &&
		ft_strncmp(line, "EA ", 3) != 0 &&
		ft_strncmp(line, "F ", 2) != 0 &&
		ft_strncmp(line, "C ", 2) != 0)
		return (true);
	return (false);
}

void	map_info(t_game *game)
{
	int	y = 0;
	int	x;
	int	i;
	char	*line;

	printf("Area y: %d\n", game->map.area_y);
	while (y < game->map.area_y)
	{
		line = ft_strtrim(game->map.area[y], " \t");
		parse_textures(game, line);
		if (is_beg_map(line))
		{
			x = 0;
			while (line[x] != '\0')
			{
				if (ft_isalpha(line[x]))
				{
					ft_printf("Error\n Invalid map.");
					exit(EXIT_FAILURE);
				}
				x++;
			}
			if (ft_strchr(line, '1') != NULL)
			{
				game->map.map_a = (char **)malloc(sizeof(char *) * (game->map.area_y + 1));
				i = 0;
				while (y < game->map.area_y && game->map.area[y][0] != '\0')
				{
					game->map.map_a[i] = special_strtrim(ft_strdup(game->map.area[y]));
					i++;
					y++;
				}
				game->map.map_a[i] = NULL;
				game->map.mapa_y = i;
				if (y < game->map.area_y)
				{
					
				}
			}

		}
		y++;
	}
	print_arr(game->map.map_a);
	if (!game->map.no_texture || !game->map.so_texture || !game->map.we_texture || !game->map.ea_texture)
	{
		ft_printf("Error\n Not all required textures are specified.");
		exit(EXIT_FAILURE);
	}
}
/* Guarda as texturas, cores e o mapa em lugares diferentes para serem tratados.|
Aloca memória para o map_a que é onde guardamos o mapa para fazer as validações e futuramente usar para renderizar o mapa. */
// tem que dar free na map_a!!!