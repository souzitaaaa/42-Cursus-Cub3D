#include "../../includes/cub3d.h"

int	encode_rgb(uint8_t red, uint8_t green, uint8_t blue)
{
	return (red << 16 | green << 8 | blue);
}

void get_mapa_x(t_game *game)
{
	int i;
	int len;
	int x;

	i = 1;
	x = ft_strlen(game->map.map_a[0]);
	ft_printf("\n\nx: %i\n", x);
	len = 0;
	while (i < game->map.mapa_y) {
		printf("Map y: %i\n", game->map.mapa_y);
		len = ft_strlen(game->map.map_a[i]);
		ft_printf("\n\nlen: %i\n", len);
		if (len > x)
			x = len;
		i++;
	}
	game->map.mapa_x = x;
	printf("Map x: %i\n", game->map.mapa_x);
}

void get_mapa_y(t_game *game)
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
	game->map.mapa_y = y;
	close(game->map.fd);
}