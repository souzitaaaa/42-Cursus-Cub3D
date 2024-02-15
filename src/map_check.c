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

void wall_space_right(t_game *game, int i) {
	int len;

	len = ft_strlen(game->map.area[i]) - 1;
	while (len >= 0)
	{
		if (game->map.area[i][len] == ' '){
			len--;
		}
		else {
			if (game->map.area[i][len] == '1')
				return;
			else {
				printf("Error\n The map isn't surrounded by walls\n");
				//! FREE
				exit(EXIT_FAILURE);
			}
		}
	}
}

void wall_space_left(t_game *game, int i) {
	int len;
	int j;

	j = 0;
	len = ft_strlen(game->map.area[i]) - 1;
	while (j < len)
	{
		if (game->map.area[i][j] == ' '){
			j++;
		}
		else {
			if (game->map.area[i][j] == '1')
				return;
			else {
				printf("Error\n The map isn't surrounded by walls\n");
				//! FREE
				exit(EXIT_FAILURE);
			}
		}
	}
}

void check_walls(t_game *game)
{
	int i;
	int len;
	int total_len;

	i = 0;
	len = 0;
	total_len = 0;
	while (i < game->map.map_y) {
		if (game->map.area[i][0] == '1' && game->map.area[i][ft_strlen(game->map.area[i]) - 1] == '1')
			game->map.map_x++;
		else if (game->map.area[i][0] == '1' && game->map.area[i][ft_strlen(game->map.area[i]) - 1] == ' ')
			wall_space_right(game, i);
		else if (game->map.area[i][0] == ' ' && game->map.area[i][ft_strlen(game->map.area[i]) - 1] == '1')
			wall_space_left(game, i);
		else if (game->map.area[i][0] == ' ' && game->map.area[i][ft_strlen(game->map.area[i]) - 1] == ' ')
		{
			game->map.map_x++;

		}
		else {
			total_len = ft_strlen(game->map.area[i]) - 1;
			len = ft_strclen(game->map.area[i], '1');
			if (len != total_len){
				game->map.map_x++;
			}
			else {
				printf("Error\n The map isn't surrounded by walls\n");
				//! FREE
				exit(EXIT_FAILURE);
			}
		}
		i++;
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
	printf("Map x: %i\n", game->map.map_x);
	printf("Map y: %i\n", game->map.map_y);
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
	//* Check if surrounded by walls
	//* End
}
