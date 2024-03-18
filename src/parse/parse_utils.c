#include "../../includes/cub3d.h"
#include <stdint.h>

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
	len = 0;
	while (i < game->map.mapa_y) {
		len = ft_strlen(game->map.map_a[i]);
		if (len > x)
			x = len;
		i++;
	}
	game->map.mapa_x = x;
}