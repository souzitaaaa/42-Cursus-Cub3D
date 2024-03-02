#include "../../includes/cub3d.h"

/*Incluir a validação se os numeros estao separados por virgulas incialmente*/
void	floor_colors(t_game *game)
{
	int		i = 0;
	char	*color_str;
	int		color_values[3] = {0};
	int		count = 0;
	int		found_floor = 0;
	char	*ptr;

	while (i < game->map.map_y && !found_floor)
	{
		if (ft_strncmp(game->map.area[i], "F ", 2) == 0)
		{
			color_str = game->map.area[i] + 2;
			ptr = color_str;
			
			while (*ptr != '\0' && count < 3) {
				while (*ptr == ' ' || *ptr == '\t')
					ptr++;
				color_values[count++] = ft_atoi(ptr);

				while (*ptr != ',' && *ptr != '\0')
					ptr++;
				if (*ptr == ',')
					ptr++;
			}
			if (count != 3)
				printf("Error\n Invalid floor color format.\n");
			else
			{
				game->map.f_range[0] = color_values[0];
				game->map.f_range[1] = color_values[1];
				game->map.f_range[2] = color_values[2];
				if (game->map.f_range[0] < 0 || game->map.f_range[0] > 255 || game->map.f_range[1] < 0 || game->map.f_range[1] > 255 || game->map.f_range[2] < 0 || game->map.f_range[2] > 255){
					ft_printf("Error\n invalid color range.\n");
					exit(EXIT_FAILURE);
				}
				printf("Floor color range: %d, %d, %d\n", game->map.f_range[0], game->map.f_range[1], game->map.f_range[2]);
			}
			found_floor = 1;
		}
		i++;
	}
}

void	ceiling_colors(t_game *game)
{
	int		i = 0;
	char	*color_str;
	int		color_values[3] = {0};
	int 	count = 0;
	int 	found_floor = 0;
	char 	*ptr;

	while (i < game->map.map_y && !found_floor)
	{
		if (ft_strncmp(game->map.area[i], "C ", 2) == 0)
		{
			color_str = game->map.area[i] + 2;
			ptr = color_str;
			
			while (*ptr != '\0' && count < 3) {
				while (*ptr == ' ' || *ptr == '\t')
					ptr++;
				color_values[count++] = ft_atoi(ptr);

				while (*ptr != ',' && *ptr != '\0')
					ptr++;
				if (*ptr == ',')
					ptr++;
			}
			if (count != 3)
				printf("Error\n Invalid floor color format.\n");
			else
			{
				game->map.c_range[0] = color_values[0];
				game->map.c_range[1] = color_values[1];
				game->map.c_range[2] = color_values[2];
				if (game->map.c_range[0] < 0 || game->map.c_range[0] > 255 || game->map.c_range[1] < 0 || game->map.c_range[1] > 255 || game->map.c_range[2] < 0 || game->map.c_range[2] > 255){
					ft_printf("Error\n invalid color range.\n");
					exit(EXIT_FAILURE);
				}
				printf("Floor color range: %d, %d, %d\n", game->map.c_range[0], game->map.c_range[1], game->map.c_range[2]);
			}
			found_floor = 1;
		}
		i++;
	}
}

