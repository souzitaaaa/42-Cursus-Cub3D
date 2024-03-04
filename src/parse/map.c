#include "../../includes/cub3d.h"

void	map_info(t_game *game)
{
	int	i = 0;
	int	j;
	int	k;
	char	*line;

	while (i < game->map.map_y + 1)
	{
		line = ft_strtrim(game->map.area[i], " \t");
		if (line[0] != '\0') {
			if (ft_strncmp(line, "NO ", 3) == 0)
				game->map.no_texture = ft_strdup(line + 3);
			else if (ft_strncmp(line, "SO ", 3) == 0)
				game->map.so_texture = ft_strdup(line + 3);
			else if (ft_strncmp(line, "WE ", 3) == 0)
				game->map.we_texture = ft_strdup(line + 3);
			else if (ft_strncmp(line, "EA ", 3) == 0)
				game->map.ea_texture = ft_strdup(line + 3);
			else if (ft_strncmp(line, "F ", 2) == 0)
				floor_colors(game);
			else if (ft_strncmp(line, "C ", 2) == 0)
				ceiling_colors(game);
			else
			{
				j = 0;
				while (line[j] != '\0')
				{
					if (ft_isalpha(line[j]))
					{
						ft_printf("Error\n Invalid character in map.");
						exit(EXIT_FAILURE);
					}
					j++;
				}
				if (ft_strchr(line, '1') != NULL)
				{
					game->map.map_a = (char **)malloc(sizeof(char *) * (game->map.map_y + 1));
					k = 0;
					while (i < game->map.map_y + 1 && game->map.area[i] != NULL)
					{
						game->map.map_a[k] = ft_strdup(game->map.area[i]);
						printf("map_a: %s\n", game->map.map_a[k]);
						k++;
						i++;
					}
					game->map.map_a[k] = '\0';
					break ;
				}
			}
		}
		i++;
	}
}
//tem que dar free na map_a!!!